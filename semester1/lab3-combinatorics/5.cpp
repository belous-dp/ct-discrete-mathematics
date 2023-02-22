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

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> res;
    for (int i = 0; i < k; ++i)
        res.push_back({ i });
    for (int i = 1; i < n; ++i) {
        vector<vector<int>> next;
        for (int j = 0; j < k; ++j) {
            for (auto &el : res) {
                next.push_back(el);
                next.back().push_back(j);
            }
            reverse(all(res));
        }
        res = next;
    }
    for (auto &i : res) {
        for (int &j : i)
            cout << j;
        cout << '\n';
    }
}