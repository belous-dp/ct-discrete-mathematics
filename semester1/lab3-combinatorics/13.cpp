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
    vector<ll> fact(19);
    fact[0] = 1;
    for (int i = 1; i < 19; ++i)
        fact[i] = fact[i - 1] * i;
    int n;
    ll k;
    cin >> n >> k;
    vector<bool> used(n);
    for (int i = 0; i < n; ++i) {
        ll sum = 0;
        for (int j = 0; j < n; ++j) {
            if (used[j])
                continue;
            // debug(j);
            // debug(sum);
            // debug(k);
            if (sum + fact[n - i - 1] > k) {
                cout << j + 1 << ' ';
                k -= sum;
                used[j] = true;
                break;
            } else {
                sum += fact[n - i - 1];
            }
        }
    }
    cout << '\n';
}