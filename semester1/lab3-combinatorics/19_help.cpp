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

void rec(int pos, string st, string res) {
    int bal = st.size();
    if (pos == 2 * n) {
        if (bal == 0)
            cout << res << '\n';
        return;
    }
    if (2 * n - pos - 1 >= bal + 1) {
        rec(pos + 1, st + "(", res + "(");
    }
    if (bal > 0 && st.back() == '(') {
        st.pop_back();
        rec(pos + 1, st, res + ")");
        st += "(";
    }
    if (2 * n - pos - 1 >= bal + 1) {
        rec(pos + 1, st + "[", res + "[");
    }
    if (bal > 0 && st.back() == '[') {
        st.pop_back();
        rec(pos + 1, st, res + "]");
        st += "[";
    }
}

void solve() {
    cin >> n;
    rec(0, "", "");
}