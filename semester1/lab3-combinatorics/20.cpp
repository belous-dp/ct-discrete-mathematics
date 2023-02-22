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
using ull = unsigned long long;

constexpr int MAXN = 45;
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

vector<vector<ull>> cnt(MAXN, vector<ull>(MAXN));

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    n /= 2;

    for (int i = 0; i < MAXN; ++i)
        cnt[i].assign(MAXN, 0);
    cnt[0][0] = 1;
    for (int i = 1; i <= 2 * n; ++i) {
        cnt[i][0] = cnt[i - 1][1];
        for (int j = 1; j <= n && 2 * n - i >= j; ++j)
            cnt[i][j] = cnt[i - 1][j - 1] + cnt[i - 1][j + 1];
    }

        ull k = 0;
    string st;
    for (int i = 0; i < 2 * n; ++i) {
        ull x = 0, y = 0;
        ull ONE = 1;
        x = ONE << ((2 * n - i - 1 - (st.size() + 1)) / 2);
        x *= cnt[2 * n - i - 1][st.size() + 1];
        if (!st.empty()) {
            y = ONE << ((2 * n - i - 1 - (st.size() - 1)) / 2);
            y *= cnt[2 * n - i - 1][st.size() - 1];
        }
        if (s[i] == '(') {
            st += '(';
            continue;
        }
        k += x;
        if (!st.empty() && st.back() == '(') {
            if (s[i] == ')') {
                st.pop_back();
                continue;
            }
            k += y;
        }
        if (s[i] == '[') {
            st += '[';
            continue;
        }
        k += x;
        if (s[i] == ']') {
            st.pop_back();
            continue;
        }
        assert(false);
    }
    cout << k << endl;
}