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

void print(vector<int> &v) {
    for (int i : v)
        cout << i;
    cout << '\n';
}

void inc(vector<int> &v) {
    for (int &i : v)
        i = (i + 1) % 3;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < (int)pow(3, n - 1); ++i) {
        vector<int> cur(n);
        for (int j = 0; j < n; ++j)
            cur[j] = (i / (int)pow(3, j)) % 3;
        print(cur);
        inc(cur);
        print(cur);
        inc(cur);
        print(cur);
    }
}