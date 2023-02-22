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
    string s;
    cin >> s;
    int n = s.size();
    n /= 2;
    vector<vector<ll>> cnt(2 * n + 1, vector<ll>(n + 2));
    cnt[0][0] = 1;
    for (int i = 1; i <= 2 * n; ++i) {
        cnt[i][0] = cnt[i - 1][1];
        for (int j = 1; j <= n && 2 * n - i >= j; ++j)
            cnt[i][j] = cnt[i - 1][j - 1] + cnt[i - 1][j + 1];
    }

    // for (auto &i : cnt) {
    //     for (ll &j : i)
    //         cout << j << ' ';
    //     cout << '\n';
    // }

    int bal = 0;
    ll ans = 0;
    for (int i = 0; i < 2 * n; ++i) {
        if (s[i] == '(') {
            bal++;
        } else {
            ans += cnt[2 * n - i - 1][bal + 1];
            bal--;
        }
    }
    cout << ans << '\n';
}