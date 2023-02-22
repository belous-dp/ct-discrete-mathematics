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

string genMin(int len) {
    string res;
    for (int i = 0; i < len; ++i)
        res += '0';
    return res;
}

string genMax(int len) {
    string res;
    for (int i = 0; i < len; ++i)
        res += '1';
    return res;
}

void solve() {
    string v;
    cin >> v;
    int n = v.size();
    string prev = "-";
    for (int i = n - 1; i >= 0; --i) {
        if (v[i] == '1') {
            prev = v.substr(0, i) + "0" + genMax(n - i - 1);
            break;
        }
    }
    cout << prev << '\n';
    string next = "-";
    for (int i = n - 1; i >= 0; --i) {
        if (v[i] == '0') {
            next = v.substr(0, i) + "1" + genMin(n - i - 1);
            break;
        }
    }
    cout << next << '\n';
}