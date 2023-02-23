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

struct vertex {
    int id;
    size_t degree;
    bool operator<(vertex const& other) const {
        if (degree != other.degree) {
            return degree > other.degree;
        }
        return id > other.id;
    }

};

void solve() {
    int n;
    cin >> n;
    vector<set<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].insert(b);
        g[b].insert(a);
    }
    priority_queue<vertex> q;
    for (int i = 0; i < n; ++i) {
        q.push({ i, g[i].size() });
    }
    vector<bool> used(n);
    int cnt = 0;
    while (cnt < n - 2) {
        vertex v = q.top();
        q.pop();
        if (used[v.id]) {
            continue;
        }
        cnt++;
        used[v.id] = true;
        assert(v.degree == 1);
        int par = *g[v.id].begin();
        cout << par + 1 << ' ';
        g[par].erase(v.id);
        q.push({ par, g[par].size() });
    }
    cout << '\n';
}