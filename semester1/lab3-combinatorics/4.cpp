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

void print(int x) {
    for (int i = n - 1; i >= 0; --i)
        cout << (char)(((x >> i) & 1) + '0');
    cout << '\n';
}

void solve() {
    cin >> n;
    set<int> used;
    int last = 0;
    print(last);
    used.insert(last);
    while (true) {
        int next = (last & ((1 << (n - 1)) - 1)) << 1;
        next |= 1;
        if (used.count(next)) {
            next ^= 1;
            if (used.count(next))
                break;
        }
        last = next;
        print(last);
        used.insert(last);
    }
}