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

constexpr int BS = 32;

void solve() {
    int n;
    cin >> n;
    int k = 0;
    vector<int> xId;
    vector<vector<int>> g(n);
    vector<bitset<BS>> f(n);
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        if (m == 0) {
            xId.push_back(i);
            k++;
        } else {
            for (int j = 0; j < m; ++j) {
                int from;
                cin >> from;
                g[i].push_back(from - 1);
            }
            for (int j = 0; j < (1 << m); ++j) {
                int x;
                cin >> x;
                if (x)
                    f[i].set(j);
            }
        }
    }
    vector<int> depth(n);
    for (int i = 0; i < n; ++i)
        for (int j : g[i])
            depth[i] = max(depth[i], depth[j] + 1);
    cout << *max_element(all(depth)) << '\n';
    for (int i = 0; i < (1 << k); ++i) {
        vector<int> val(n);
        for (int j = 0, l = 0; j < n; ++j) {
            if (l < k && j == xId[l]) {
                val[j] = (i >> (k - l - 1)) & 1;
                l++;
            } else {
                int res = 0;
                for (int r = 0; r < g[j].size(); ++r)
                    res += val[g[j][r]] * (1 << ((int)g[j].size() - r - 1));
                val[j] = f[j].test(res);
            }
        }
        cout << val.back();
    }
    cout << '\n';
}