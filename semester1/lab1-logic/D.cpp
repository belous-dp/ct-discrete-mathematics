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

struct Node {
    int type = -1;
    int from1 = -1, from2 = -1;
};

void solve() {
    int n;
    cin >> n;
    vector<Node> g(n);
    for (int i = 0; i < n; ++i)
        g.push_back({ 1, i });
    int lastDisjunction = -1;
    for (int i = 0; i < (1 << n); ++i) {
        string s;
        int x;
        cin >> s >> x;
        if (x) {
            g.push_back({ 2, 0, 1 });
            if (s[0] == '0')
                g.back().from1 += n;
            if (s[1] == '0')
                g.back().from2 += n;
            for (int j = 2; j < n; ++j) {
                g.push_back({ 2, (int)g.size() - 1, j });
                if (s[j] == '0')
                    g.back().from2 += n;
            }
            if (lastDisjunction != -1)
                g.push_back({ 3, lastDisjunction, (int)g.size() - 1 });
            lastDisjunction = g.size() - 1;
        }
    }
    if ((int)g.size() == 2 * n)
        g.push_back({ 2, 0, n });
    cout << g.size() << '\n';
    for (int i = n; i < g.size(); ++i) {
        cout << g[i].type << ' ' << g[i].from1 + 1;
        if (g[i].type > 1)
            cout << ' ' << g[i].from2 + 1;
        cout << '\n';
    }
}