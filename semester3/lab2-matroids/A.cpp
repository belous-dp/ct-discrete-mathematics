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

#define TASK "schedule"
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
    int n;
    cin >> n;
    ll sum_all = 0;
    int max_d = 0;
    vector<pii> tasks(n);
    for (auto& [w, d] : tasks) {
        cin >> d >> w;
        sum_all += w;
        max_d = max(max_d, d);
        d--;
    }
    sort(tasks.rbegin(), tasks.rend());
    // matroid: <X = <time, task_num>, I = { A | penalty(A) == 0 }>
    vector<int> base;
    set<pii> free; // segments of free time
    free.insert({ 0, max_d });
    for (int i = 0; i < n && !free.empty(); ++i) { // rado-edmonds greedy algorithm
        int d = tasks[i].second;
        auto segm = free.upper_bound({ d, INF });
        if (segm != free.begin()) { // independent
            base.push_back(i);
            segm--;
            auto [a, b] = *segm;
            free.erase(segm);
            if (b <= d) {
                d = b - 1;
            }
            if (d - a > 0) {
                free.insert({ a, d });
            }
            if (b - d > 1) {
                free.insert({ d + 1, b });
            }
        }
    }
    for (int i : base) {
        sum_all -= tasks[i].first;
    }
    cout << sum_all << '\n';
}