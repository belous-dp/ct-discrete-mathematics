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

vector<int> genMin(int len, vector<bool> &used) {
    vector<int> res;
    for (int i = 0; i < used.size() && res.size() < len; ++i)
        if (!used[i])
            res.push_back(i);
    return res;
}

vector<int> genMax(int len, vector<bool> &used) {
    vector<int> res;
    for (int i = (int)used.size() - 1; i >= 0 && res.size() < len; --i)
        if (!used[i])
            res.push_back(i);
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v) {
        cin >> i;
        i--;
    }
    // 4 5 3 6 1
    // 4 5 6 1 3

    // 4 3 5 2 1
    // 4 5 1 2 3

    // 5 1 2 3 4
    // 5 1 2 4 3

    // 4 5 3 2 1
    // 5 1 2 3 4
    vector<int> prev(n, -1);
    vector<bool> used(n, true);
    used[v.back()] = false;
    for (int i = n - 2; i >= 0; --i) {
        used[v[i]] = false;
        if (v[i] > v[i + 1]) {
            for (int j = v[i] - 1; j >= 0; --j)
                if (!used[j]) {
                    prev = v;
                    prev[i] = j;
                    used[j] = true;
                    vector<int> suf = genMax(n - i - 1, used);
                    for (int k = i + 1; k < n; ++k)
                        prev[k] = suf[k - i - 1];
                    break;
                }
            break;
        }
    }
    for (int &i : prev)
        cout << i + 1 << ' ';
    cout << '\n';

    vector<int> next(n, -1);
    used.assign(n, true);
    used[v.back()] = false;
    for (int i = n - 2; i >= 0; --i) {
        used[v[i]] = false;
        if (v[i] < v[i + 1]) {
            for (int j = v[i] + 1; j < n; ++j)
                if (!used[j]) {
                    next = v;
                    next[i] = j;
                    used[j] = true;
                    vector<int> suf = genMin(n - i - 1, used);
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