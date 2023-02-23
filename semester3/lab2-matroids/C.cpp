#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#define TASK "matching"
#define mp make_pair
#define all(x) (x).begin(), (x).end()
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
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q = 1;
    if (multi_test) cin >> q;
    while (q--) solve();
}

/*-------------------------------------------------------------------------------------------------------*/

bool dfs(int v, vector<bool>& used, vector<pii>& matching, vector<vector<int>> const& g) {
    if (used[v]) {
        return false;
    }
    used[v] = true;
    for (int u : g[v]) {
        if (matching[u].second == -1 || dfs(matching[u].second, used, matching, g)) {
            matching[v].first = u;
            matching[u].second = v;
            return true;
        }
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<pii> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i].first;
        w[i].second = i;
    }
    vector<vector<int>> g(2 * n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int to;
            cin >> to;
            to = n + to - 1;
            g[i].push_back(to);
            g[to].push_back(i);
        }
    }
    sort(w.rbegin(), w.rend());
    vector<pii> matching(2 * n, { -1, -1 });
    for (pii i : w) {
        vector<bool> used(2 * n);
        dfs(i.second, used, matching, g);
    }
    for (int i = 0; i < n; ++i) {
        cout << (matching[i].first == -1 ? 0 : matching[i].first - n + 1) << ' ';
    }
    cout << '\n';
}