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

vector<vector<int>> rec(int n, int k) {
    if (n == 0)
        return { { } };
    vector<vector<int>> res;
    for (int i = k; i <= n && n >= i; ++i) {
        vector<vector<int>> tmp = rec(n - i, i);
        for (auto &j : tmp) {
            reverse(all(j));
            j.push_back(i);
            reverse(all(j));
            res.push_back(j);
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<vector<int>> res = rec(n, 1);
    cerr << "ans size: " << res.size() << endl;
    for (auto &i : res) {
        for (int j = 0; j < (int)i.size(); ++j) {
            cout << i[j];
            if (j + 1 < (int)i.size())
                cout << '+';
        }
        cout << '\n';
    }
}