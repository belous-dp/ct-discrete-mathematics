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
    bool term;
    ll sumfq;
    vector<int> to;
};

vector<Node> trie;
ll ans = 0;

void dfs(int v, int len) {
    if (trie[v].term) {
        ans += (len) * trie[v].sumfq;
        return;
    }
    for (int u : trie[v].to)
        dfs(u, len + 1);
}


void solve() {
    int n;
    cin >> n;
    trie.resize(n + 1);
    int triesz = n + 1;
    priority_queue<pli> q;
    for (int i = 1; i <= n; ++i) {
        int fq;
        cin >> fq;
        q.push({ -fq, i });
        trie[i] = { true, fq };
    }
    for (int i = 1; i < n; ++i) {
        int l = q.top().second;
        q.pop();
        int r = q.top().second;
        q.pop();
        q.push({ -trie[l].sumfq + -trie[r].sumfq, triesz++ });
        trie.push_back({ false, trie[l].sumfq + trie[r].sumfq, {l, r} });
    }
    dfs(triesz - 1, 0);
    cout << ans << '\n';
}