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

vector<int> genMin(int len, int start) {
    vector<int> res;
    for (int i = start; res.size() < len; ++i)
        res.push_back(i);
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(k);
    for (int &i : v) {
        cin >> i;
        i--;
    }

    vector<int> next(k, -1);
    for (int i = k - 1; i >= 0; --i) {
        if (v[i] + 1 < n && (i == k - 1 || v[i] + 1 < v[i + 1])) {
            next = v;
            next[i] = v[i] + 1;
            vector<int> suf = genMin(k - i - 1, v[i] + 2);
            for (int j = i + 1; j < k; ++j)
                next[j] = suf[j - i - 1];
            break;
        }
    }
    if (next[0] == -1) {
        cout << "-1\n";
        return;
    }
    for (int &i : next)
        cout << i + 1 << ' ';
    cout << '\n';
}