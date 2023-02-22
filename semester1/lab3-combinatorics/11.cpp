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
    vector<vector<int>> ans;
    for (int i = 0; i < (1 << n); ++i) {
        vector<int> cur;
        for (int j = 0; j < n; ++j)
            if ((i >> j) & 1)
                cur.push_back(j + 1);
        ans.push_back(cur);
    }
    sort(all(ans));
    for (auto &i : ans) {
        for (int &j : i)
            cout << j << ' ';
        cout << '\n';
    }
}