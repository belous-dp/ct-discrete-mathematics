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
    int n;
    cin >> n;
    vector<vector<int>> res = { { 0 }, { 1 } };
    for (int i = 1; i < n; ++i) {
        vector<vector<int>> next;
        for (auto &j : res) {
            next.push_back(j);
            next.back().push_back(0);
        }
        reverse(all(res));
        for (auto &j : res) {
            next.push_back(j);
            next.back().push_back(1);
        }
        res = next;
    }
    for (auto &i : res) {
        for (int &j : i)
            cout << j;
        cout << '\n';
    }
}