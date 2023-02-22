#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define all(x) x.begin(), x.end()
#define multi_test 0
#define debug(x) cerr << #x << " = " << x << endl;

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
    vector<vector<int>> c(31, vector<int>(31));
    c[0][0] = 1;
    for (int i = 1; i < 31; ++i) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; ++j)
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
    // for (int i = 0; i < 10; ++i) {
    //     for (int j = 0; j <= i; ++j)
    //         cout << c[i][j] << ' ';
    //     cout << '\n';
    // }
    int n, k;
    ll m;
    cin >> n >> k >> m;
    vector<bool> used(n);
    for (int i = 0; i < k; ++i) {
        ll sum = 0;
        int lastused = -1;
        for (int j = 0; j < n; ++j)
            if (used[j])
                lastused = j;
        for (int j = lastused + 1; j < n; ++j) {
            // debug(i);
            // debug(j);
            // debug(sum);
            // debug(m);
            if (sum + c[n - j - 1][k - i - 1] > m) {
                m -= sum;
                used[j] = true;
                cout << j + 1 << ' ';
                break;
            }
            sum += c[n - j - 1][k - i - 1];
        }
    }
}