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
    int n = 105;
    vector<vector<vector<ll>>> p(n, vector<vector<ll>>(n, vector<ll>(n)));
    for (int from = 0; from < n; ++from) {
        for (int to = 0; to < n; ++to)
            p[0][from][to] = 1;
        p[from][from][from] = 1;
        for (int i = from; i < n; ++i) {
            for (int to = from; to <= i; ++to)
                if (to > 0 && (from != i || to != i))
                    p[i][from][to] = p[i - to][from][to] + p[i][from][to - 1];
            for (int to = i + 1; to < n; ++to)
                p[i][from][to] = p[i][from][to - 1];
        }
    }

    // for (int k = 0; k < n; ++k) {
    //     cout << "k = " << k << endl;
    //     for (auto &i : p) {
    //         for (auto &j : i[k])
    //             cout << j << ' ';
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    n = 0;
    string s;
    cin >> s;
    s += '+';
    vector<int> v;
    string cur;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '+') {
            assert(!cur.empty());
            v.push_back(stoi(cur));
            n += v.back();
            cur.clear();
        } else {
            cur += s[i];
        }
    }
    
    // cout << n << endl;

    ll ans = 0;
    int last = 1;
    for (int i = 0; i < v.size(); ++i) {
        for (; last < v[i]; ++last) {
            ans += p[n - last][last][n - last];
        }
        n -= v[i];
    }
    cout << ans << '\n';
}