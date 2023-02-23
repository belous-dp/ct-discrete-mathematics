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

#define TASK "problem1"
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

void solve() {
    string s;
    cin >> s;
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> aut(n, vector<int>(26, -1));
    vector<bool> terminal(n);
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
    int id = 0;
    for (int i = 0; i < s.size(); ++i) {
        id = aut[id][s[i] - 'a'];
        if (id == -1) {
            cout << "Rejects\n";
            return;
        }
    }
    cout << (terminal[id] ? "Accepts\n" : "Rejects\n");
}