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

#define TASK "destroy"
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define multi_test 0

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

constexpr int MAXN = 5e4 + 7;
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

int par[MAXN], rnk[MAXN];

int find_set(int x) {
    if (par[x] == x) {
        return x;
    }
    return par[x] = find_set(par[x]);
}

void unite_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rnk[a] < rnk[b]) {
            swap(a, b);
        } else if (rnk[a] == rnk[b]) {
            rnk[a]++;
        }
        par[b] = a;
    }
}

struct Edge {
    int a, b, id;
    ll w;
    bool operator<(Edge const& other) const {
        return w > other.w;
    }
};

void kruskal(int n, vector<Edge>& edges, vector<bool>& used) {
    for (int i = 0; i < n; ++i) {
        par[i] = i;
    }
    sort(all(edges));
    for (int i = 0; i < edges.size(); ++i) {
        Edge e = edges[i];
        if (find_set(e.a) != find_set(e.b)) {
            unite_sets(e.a, e.b);
            used[i] = true;
        }
    }
}

void solve() {
    int n, m;
    ll s;
    cin >> n >> m >> s;
    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].a >> edges[i].b >> edges[i].w;
        edges[i].a--;
        edges[i].b--;
        edges[i].id = i + 1;
    }
    vector<bool> used(m);
    kruskal(n, edges, used);
    vector<int> ans;
    for (int i = m - 1; i >= 0; --i) {
        if (used[i]) {
            continue;
        }
        if (s >= edges[i].w) {
            s -= edges[i].w;
            ans.push_back(edges[i].id);
        } else {
            break;
        }
    }
    cout << ans.size() << '\n';
    for (int i : ans) {
        cout << i << ' ';
    }
    cout << '\n';
}