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

#define TASK "problem4"
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

const int ALPH = 26;

int n;
vector<vector<int>> aut;
vector<bool> terminal;

int add(int a, int b) {
    if (a + b >= MOD)
        return a + b - MOD;
    return a + b;
}

void solve() {
    int m, k, len;
    cin >> n >> m >> k >> len;
    aut.resize(n, vector<int>(ALPH, -1));
    terminal.resize(n);
    for (int i = 0; i < k; ++i) {
        int id;
        cin >> id;
        terminal[id - 1] = true;
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        aut[a - 1][c - 'a'] = b - 1;
    }
    vector<int> cnt(n);
    cnt[0] = 1;
    for (int i = 0; i < len; ++i) {
        vector<int> next_cnt(n);
        for (int v = 0; v < n; ++v) {
            for (int j = 0; j < ALPH; ++j) {
                int u = aut[v][j];
                if (u != -1) {
                    next_cnt[u] = add(next_cnt[u], cnt[v]);
                }
            }
        }
        cnt = next_cnt;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
        if (terminal[i])
            ans = add(ans, cnt[i]);
    cout << ans << '\n';
}