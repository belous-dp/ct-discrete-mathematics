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

vector<int> genMin(int val, int start) {
    vector<int> res;
    for (int i = 0; i < val / start - 1; ++i)
        res.push_back(start);
    res.push_back(start + val % start);
    return res;
}

void solve() {
    string s;
    cin >> s;
    s += '+';
    string cur;
    int n;
    vector<int> v;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '=') {
            n = stoi(cur);
            cur.clear();
            for (i = i + 1; i < s.size(); ++i) {
                if (s[i] == '+')  {
                    v.push_back(stoi(cur));
                    cur.clear();
                } else {
                    cur += s[i];
                }
            }
            break;
        }
        cur += s[i];
    }

    if (v.size() == 1) {
        cout << "No solution\n";
        return;
    }

    vector<int> next = v;
    next[next.size() - 2]++;
    next[next.size() - 1]--;
    if (next[next.size() - 2] > next[next.size() - 1]) {
        next[next.size() - 2] += next[next.size() - 1];
        next.pop_back();
    } else {
        vector<int> suf = genMin(next.back(), next[next.size() - 2]);
        next.pop_back();
        for (int &i : suf)
            next.push_back(i);
    }
    cout << n << '=';
    for (int i = 0; i < next.size(); ++i) {
        cout << next[i];
        if (i + 1 < next.size())
            cout << '+';
    }
    cout << '\n';
}