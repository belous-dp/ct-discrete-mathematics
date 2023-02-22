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

string genMin(int len, int bal) {
    string res;
    for (int i = 0; i < len; ++i) {
        if (len - i - 1 >= bal + 1) {
            res += '(';
            bal++;
        } else {
            res += ')';
            bal--;
        }
    }
    return res;
}

void solve() {
    string v;
    cin >> v;
    int n = v.size();
    n /= 2;

    string next = "-";
    int bal = 0;
    for (char c : v)
        bal += c == '(' ? 1 : -1;
    for (int i = 2 * n - 1; i >= 0; --i) {
        // cout << "pos: " << i << ", sym: " << v[i] << endl;
        // cout << "bal: " << bal << ", bal >= 2: " << (bal - 2 >= 0) << ", can build suff: " << (bal - 2 <= 2 * n - i - 1) << endl;
        // cout << "can build suff with required bal: " << ((2 * n - i - 1 - (bal - 2)) % 2 == 0) << endl;
        if (v[i] == '(' && bal - 2 >= 0 && bal - 2 <= 2 * n - i - 1 && (2 * n - i - 1 - (bal - 2)) % 2 == 0) {
            next = v.substr(0, i);
            next += ')';
            // cout << "next = " << next << endl;
            next += genMin(2 * n - i - 1, bal - 2);
            break;
        }
        bal -= v[i] == '(' ? 1 : -1;
    }
    if (next[0] == -1) {
        cout << "-1\n";
        return;
    }
    cout << next << '\n';
}