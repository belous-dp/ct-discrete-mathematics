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

#define TASK "cycles"
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

bool contains_cycle(int mask, vector<int> const& cycles) {
    for (int c : cycles) {
        if ((mask & c) == c) {
            return true;
        }
    }
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pii> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i].first;
        w[i].second = i;
    }
    vector<int> cycles;
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        int cycle = 0;
        for (int j = 0; j < k; ++j) {
            int elem;
            cin >> elem;
            cycle += 1 << (elem - 1);
        }
        cycles.push_back(cycle);
    }
    // rado-edmonds algorithm
    sort(w.rbegin(), w.rend());
    int base = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!contains_cycle(base | (1 << w[i].second), cycles)) {
            base |= (1 << w[i].second);
            ans += w[i].first;
        }
    }
    cout << ans << '\n';
}