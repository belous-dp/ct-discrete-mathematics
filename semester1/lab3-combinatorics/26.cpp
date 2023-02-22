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
    int q = 10000;
    if (multi_test) cin >> q;
    while (q--) solve();
}

/*-------------------------------------------------------------------------------------------------------------*/

int n, k;

void printAns(vector<vector<int>> &v, vector<bool> &used) {
    for (int j = 0; j < n; ++j)
        if (!used[j])
            v.push_back({ j });
    cout << n << ' ' << v.size() << '\n';
    for (auto &i : v) {
        for (int &j : i)
            cout << j + 1 << ' ';
        cout << '\n';
    }
    cout << '\n';
}

int getMinNotUsed(int from, vector<bool> &used) {
    for (int j = from + 1; j < n; ++j)
        if (!used[j])
            return j;
    return -1;
}

void solve() {
    cin >> n >> k;
    if (n == 0)
        exit(0);
    vector<vector<int>> v(k);
    string line;
    getline(cin, line);
    for (auto &i : v) {
        getline(cin, line);
        line += ' ';
        string s;
        for (char c : line) {
            if (c == ' ') {
                i.push_back(stoi(s) - 1);
                s.clear();
            } else if ('0' <= c && c <= '9') {
                s += c;
            }
        }
    }
    vector<bool> used(n, true);
    while (!v.empty()) {
        int id = getMinNotUsed(v.back().back(), used);
        if (id != -1) {
            v.back().push_back(id);
            used[id] = true;
            printAns(v, used);
            return;
        }
        while (!v.back().empty()) {
            id = getMinNotUsed(v.back().back(), used);
            used[v.back().back()] = false;
            if (id != -1 && v.back().size() > 1) {
                used[id] = true;
                v.back().back() = id;
                printAns(v, used);
                return;
            } else {
                v.back().pop_back();
            }
        }
        v.pop_back();
    }
    printAns(v, used);
}