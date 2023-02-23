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

#define TASK "problem5"
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
    vector<vector<int>> to{ vector<vector<int>>(ALPH) };
    bool terminal{ false };
};

vector<vertex> aut;

void thompson() {
    vector<vertex> det_aut(111);
    det_aut[0].terminal = aut[0].terminal;
    map<set<int>, int> id;
    id[{ 0 }] = 0;
    queue<set<int>> q;
    q.push({ 0 });
    while (!q.empty()) {
        set<int> cur = q.front();
        q.pop();
        for (int c = 0; c < ALPH; ++c) {
            set<int> nxt;
            bool terminal = false;
            for (int v : cur) {
                for (int u : aut[v].to[c]) {
                    nxt.insert(u);
                    terminal |= aut[u].terminal;
                }
            }
            if (nxt.empty())
                continue;
            if (id.count(nxt) == 0) {
                det_aut[id.size()].terminal = terminal;
                id[nxt] = id.size();
                q.push(nxt);
            }
            det_aut[id[cur]].to[c].push_back(id[nxt]);
        }
    }
    std::swap(aut, det_aut);
}

int add(int a, int b) {
    if (a + b >= MOD)
        return a + b - MOD;
    return a + b;
}

void solve() {
    int n, m, k, len;
    cin >> n >> m >> k >> len;
    aut.resize(n);
    for (int i = 0; i < k; ++i) {
        int id;
        cin >> id;
        aut[id - 1].terminal = true;
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        aut[a - 1].to[c - 'a'].push_back(b - 1);
    }
    thompson();
    vector<int> cnt(aut.size());
    cnt[0] = 1;
    for (int i = 0; i < len; ++i) {
        vector<int> next_cnt(aut.size());
        for (int v = 0; v < aut.size(); ++v) {
            for (int j = 0; j < ALPH; ++j) {
                if (!aut[v].to[j].empty()) {
                    assert(aut[v].to[j].size() == 1);
                    int u = aut[v].to[j][0];
                    next_cnt[u] = add(next_cnt[u], cnt[v]);
                }
            }
        }
        cnt = next_cnt;
    }
    int ans = 0;
    for (int i = 0; i < aut.size(); ++i)
        if (aut[i].terminal)
            ans = add(ans, cnt[i]);
    cout << ans << '\n';
}