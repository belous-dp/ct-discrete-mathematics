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
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q = 1;
    if (multi_test) cin >> q;
    while (q--) solve();
}

/*-------------------------------------------------------------------------------------------------------*/

void dfs(int v, int k, vector<int>& colors, vector<vector<int>> const& g) {
    colors[v] = 0;
    vector<int> cols;
    for (int u : g[v]) {
        if (colors[u] == -1) {
            dfs(u, k, colors, g);
        }
    }
    for (int u : g[v]) {
        cols.push_back(colors[u]);
    }
    sort(all(cols));
    int col = -1;
    for (int i = 1, j = 0; i <= k; ++j) {
        if (j < cols.size() && cols[j] == 0) {
            continue;
        }
        if (j >= cols.size() || cols[j] != i++) {
            col = i;
            break;
        }
    }
    assert(col > 0 && col <= k);
    colors[v] = col;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    size_t k = 0;
    while (m--) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
        k = max({ k, g[a].size(), g[b].size() });
    }
    // "lite brooks" theorem
    int start = 0; // needs default value cuz K_{2n+1} or C_{2n+1}
    for (int i = 0; i < n; ++i) {
        if (g[i].size() < k) {
            start = i; // otherwise start from the vertex that has degree < k
            break;
        }
    }
    if (k % 2 == 0) {
        k++;
    }
    vector<int> colors(n, -1);
    dfs(start, k, colors, g);
    cout << k << '\n';
    for (int i : colors) {
        assert(i != -1);
        cout << i << '\n';
    }
}