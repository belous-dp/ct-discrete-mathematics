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

vector<int> genMin(int len, vector<int> used, vector<int> &cnt) {
    vector<int> res;
    for (int i = 0; i < used.size() && res.size() < len; ++i)
        if (used[i] < cnt[i]) {
            res.push_back(i);
            used[i]++;
            i--;
        }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n), cnt(n);
    for (int &i : v) {
        cin >> i;
        i--;
        cnt[i]++;
    }
    // 4 5 3 6 1
    // 4 5 6 1 3

    // 4 3 5 2 1
    // 4 5 1 2 3

    // 5 1 2 3 4
    // 5 1 2 4 3

    // 4 5 3 2 1
    // 5 1 2 3 4

    vector<int> next(n, -1);
    vector<int> used = cnt;
    used[v.back()]--;
    for (int i = n - 2; i >= 0; --i) {
        used[v[i]]--;
        if (v[i] < v[i + 1]) {
            for (int j = v[i] + 1; j < n; ++j)
                if (used[j] < cnt[j]) {
                    next = v;
                    next[i] = j;
                    used[j]++;
                    vector<int> suf = genMin(n - i - 1, used, cnt);
                    for (int k = i + 1; k < n; ++k)
                        next[k] = suf[k - i - 1];
                    break;
                }
            break;
        }
    }
    for (int &i : next)
        cout << i + 1 << ' ';
    cout << '\n';
}