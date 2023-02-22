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

int n;

void rec(int pos, vector<int> &v, vector<int> &cnt) {
    if (pos == n) {
        for (int &i : v)
            cout << i << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] == 0) {
            cnt[i] = 1;
            v[pos] = i;
            rec(pos + 1, v, cnt);
            cnt[i] = 0;
        }
    }
}

void solve() {
    cin >> n;
    vector<int> v(n), cnt(n + 1);
    rec(0, v, cnt);
}