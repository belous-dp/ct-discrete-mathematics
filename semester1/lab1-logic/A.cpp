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

constexpr int MAXN = 1e2 + 7;
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

bool is_reflexive(int n, const vector<vector<int>> &v) {
    for (int i = 0; i < n; ++i)
        if (!v[i][i])
            return false;
    return true;
}

bool is_irreflexive(int n, const vector<vector<int>> &v) {
    for (int i = 0; i < n; ++i)
        if (v[i][i])
            return false;
    return true;
}

bool is_symmetric(int n, const vector<vector<int>> &v) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j)
            if (v[i][j] + v[j][i] == 1)
                return false;
    return true;
}

bool is_antisymmetric(int n, const vector<vector<int>> &v) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j)
            if (v[i][j] + v[j][i] == 2)
                return false;
    return true;
}

bool is_transitive(int n, const vector<vector<int>> &v) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                if (v[i][j] && v[j][k] && !v[i][k])
                    return false;
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    vector<vector<int>> b(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> b[i][j];
    cout << (int)is_reflexive(n, a) << ' ';
    cout << (int)is_irreflexive(n, a) << ' ';
    cout << (int)is_symmetric(n, a) << ' ';
    cout << (int)is_antisymmetric(n, a) << ' ';
    cout << (int)is_transitive(n, a) << ' ';
    cout << '\n';
    cout << (int)is_reflexive(n, b) << ' ';
    cout << (int)is_irreflexive(n, b) << ' ';
    cout << (int)is_symmetric(n, b) << ' ';
    cout << (int)is_antisymmetric(n, b) << ' ';
    cout << (int)is_transitive(n, b) << ' ';
    cout << '\n';
    // find composition
    vector<vector<int>> c(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                if (a[i][j] && b[j][k])
                    c[i][k] = 1;
    for (auto &i : c) {
        for (int j : i)
            cout << j << ' ';
        cout << '\n';
    }
}