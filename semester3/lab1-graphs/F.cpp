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

void solve() {
    int n;
    cin >> n;
    vector<int> code(n - 2);
    vector<int> degree(n, 1);
    for (int& i : code) {
        cin >> i;
        i--;
        degree[i]++;
    }
    int ptr = 0;
    for (; degree[ptr] > 1; ++ptr);
    int leaf = ptr;
    vector<pii> ans;
    for (int i = 0; i < n - 2; ++i) {
        int v = code[i];
        ans.push_back({ leaf, v });
        degree[leaf]--;
        degree[v]--;
        if (degree[v] == 1 && v < ptr) {
            leaf = v;
        } else {
            while (degree.at(++ptr) > 1);
            leaf = ptr;
        }
    }
    assert(ans.size() == n - 2);
    for (int i = 0; i < n - 1; ++i) {
        if (degree[i] == 1) {
            ans.push_back({ i, n - 1 });
            break;
        }
    }
    for (pii p : ans) {
        cout << p.first + 1 << ' ' << p.second + 1 << '\n';
    }
}