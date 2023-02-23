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

#define TASK "equivalence"
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

struct vertex {
    vector<int> to{ vector<int>(ALPH) };
    bool terminal{ false };
};

void read_aut(vector<vertex>& aut) {
    int n, m, k;
    cin >> n >> m >> k;
    aut.resize(n + 1, { vector<int>(ALPH, n) });
    for (int i = 0; i < k; ++i) {
        int id;
        cin >> id;
        aut[id - 1].terminal = true;
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        aut[a - 1].to[c - 'a'] = b - 1;
    }
}

vector<vertex> aut1;
vector<vertex> aut2;

void solve() {
    read_aut(aut1);
    read_aut(aut2);
    queue<pii> q;
    q.push({ 0, 0 });
    set<pii> used;
    while (!q.empty()) {
        pii vu = q.front();
        q.pop();
        int v = vu.first, u = vu.second;
        if (aut1[v].terminal != aut2[u].terminal) {
            cout << "NO\n";
            return;
        }
        used.insert({ v, u });
        for (int c = 0; c < ALPH; ++c) {
            if (used.count({ aut1[v].to[c], aut2[u].to[c] }) == 0) {
                q.push({ aut1[v].to[c], aut2[u].to[c] });
            }
        }
    }
    cout << "YES\n";
}