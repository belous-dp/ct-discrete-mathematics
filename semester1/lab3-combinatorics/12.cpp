#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define all(x) x.begin(), x.end()
#define multi_test 0

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

constexpr int MAXN = 3e5 + 7;
constexpr ll MOD = 1e9 + 7;
constexpr int INF = 1e9 + 5;
constexpr ll INF1 = 2e18;

void solve();

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q = 1;
    if (multi_test) cin >> q;
    while (q--) solve();
}

/*-------------------------------------------------------------------------------------------------------------*/

int n, k;

int ans = 0;

void rec(int pos, int numk, vector<int> &v, vector<int> &vk) {
    if (pos == n) {
        // cout << "vk: ";
        // for (int &i : vk)
        //     cout << i << ' ';
        // cout << ", v: ";
        // for (int &i : v)
        //     cout << i << " ";
        // cout << "\n";
        ans++;
        // vector<int> res;
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < n; ++j)
                if (v[j] == i)
                    cout << j + 1 << ' ';
            cout << '\n';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < k; ++i) {
        int nextnumk = numk + (vk[i] == 0);
        int cnz = 0;
        for (int j = i + 1; j < k; ++j)
            cnz += vk[j] != 0;
        if (n - pos - 1 >= k - nextnumk && i <= pos && (vk[i] > 0 || cnz == 0)) {
            v[pos] = i;
            vk[i]++;
            rec(pos + 1, nextnumk, v, vk);
            vk[i]--;
        }
    }
}

void solve() {
    cin >> n >> k;
    vector<int> v(n), vk(k);
    rec(0, 0, v, vk);
    // cerr << ans << endl;
}