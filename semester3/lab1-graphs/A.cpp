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
    vector<vector<int>> matrix(n, vector<int>(n));
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            char e;
            cin >> e;
            matrix[i][j] = matrix[j][i] = e == '1';
        }
        q.push(i);
    }
    for (int cnt = 0; cnt < n * (n - 1); ++cnt) {
        int v1 = q.front();
        q.pop();
        int v2 = q.front();
        if (matrix[v1][v2]) {
            q.push(v1);
            continue;
        }
        vector<int> qv;
        while (!q.empty()) {
            qv.push_back(q.front());
            q.pop();
        }
        
        for (int j = 1;; ++j) {
            assert(j + 1 < qv.size());
            if (matrix[v1][qv[j]] && matrix[v2][qv[j + 1]]) {
                for (int i = 0; i <= j / 2; ++i) {
                    swap(qv[i], qv[j - i]);
                }
                break;
            }
        }
        for (int i : qv) {
            q.push(i);
        }
        q.push(v1);
    }
    while (!q.empty()) {
        cout << q.front() + 1 << ' ';
        q.pop();
    }
}