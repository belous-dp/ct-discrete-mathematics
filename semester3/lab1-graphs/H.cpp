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

constexpr int MAXN = 11;
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

struct poly {
    int t[MAXN]{0};

    friend poly operator+(poly lhs, poly const& rhs) {
        for (int i = 0; i < MAXN; ++i) {
            lhs.t[i] += rhs.t[i];
        }
        return lhs;
    }
    friend poly operator-(poly lhs, poly const& rhs) {
        for (int i = 0; i < MAXN; ++i) {
            lhs.t[i] -= rhs.t[i];
        }
        return lhs;
    }

    friend ostream& operator<<(ostream& out, poly const& p) {
        int degree = MAXN;
        while (p.t[--degree] == 0);
        out << degree << '\n';
        for (int i = degree; i >= 0; --i) {
            out << p.t[i] << ' ';
        }
        out << '\n';
        return out;
    }
};

void remove_non_unique(vector<int>& v) {
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());
}

vector<vector<int>> contract(vector<vector<int>> const& g, int v) {
    int u = g[v][0];
    vector<vector<int>> res(g.size());
    for (int i = 0; i < g.size(); ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            if (g[i][j] < u) {
                res[i].push_back(g[i][j]);
            } else if (g[i][j] > u) {
                res[i].push_back(g[i][j] - 1);
            } else if (i != v) {
                res[i].push_back(v);
                res[v].push_back(i < u ? i : i - 1);
            }
        }
        remove_non_unique(res[i]);
    }
    res.erase(res.begin() + u);
    remove_non_unique(res[v]);
    return res;
}

vector<vector<int>> throw_edge(vector<vector<int>> g, int v) {
    int u = g[v][0];
    g[u].erase(find(all(g[u]), v));
    g[v].erase(g[v].begin());
    return g;
}

void print_g(vector<vector<int>> const& g) {
    cout << "n = " << g.size() << '\n';
    for (int i = 0; i < g.size(); ++i) {
        for (int j : g[i]) {
            cout << i << ' ' << j << '\n';
        }
    }
    cout << endl;
}

poly find_chr_pol(vector<vector<int>> const& g) {
    //cout << "chr pol for g:\n";
    //print_g(g);
    poly res;
    int n = g.size();
    for (int i = 0; i < n; ++i) {
        if (!g[i].empty()) {
            //cout << "edge contracting: " << i << '-' << g[i][0] << '\n';
            //print_g(contract(g, i));
            //cout << "removing edge: " << i << '-' << g[i][0] << '\n';
            //print_g(throw_edge(g, i));
            return find_chr_pol(throw_edge(g, i)) - find_chr_pol(contract(g, i));
        }
    }
    res.t[n] = 1;
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cout << find_chr_pol(g);
}