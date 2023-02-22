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

int n;

void rec(int pos, vector<int> &v) {
    if (pos == n) {
        for (int &i : v)
            cout << i;
        cout << '\n';
        return;
    }
    v[pos] = 0;
    rec(pos + 1, v);
    v[pos] = 1;
    rec(pos + 1, v);
}

void solve() {
    cin >> n;
    vector<int> v(n);
    rec(0, v);
}