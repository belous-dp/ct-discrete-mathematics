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
    vector<int> log(MAXN);
    log[0] = -INF;
    for (int i = 2; i < MAXN; ++i) {
        log[i] = log[i - 1];
        if ((1 << (log[i] + 1)) == i)
            log[i]++;
    }
    int mode;
    cin >> mode;
    string s;
    cin >> s;
    int n = s.size();
    if (mode == 1) {
        vector<int> res(n + log[n] + 2);
        for (int i = 0, j = 1; i < n; ++i, ++j) {
            if (log[j] > log[j - 1]) {
                i--;
                continue;
            } else {
                res[j] = s[i] - '0';
                for (int k = 0; k <= log[j]; ++k)
                    if ((j >> k) & 1)
                        res[1 << k] ^= res[j];
            }
        }
        for (int i = 1; i < res.size(); ++i)
            cout << res[i];
        cout << '\n';
    } else {
        s = "0" + s;
        n++;
        vector<int> res(n);
        vector<int> check(n);
        for (int j = 1; j < n; ++j) {
            res[j] = s[j] - '0';
            if (log[j] <= log[j - 1])
                for (int k = 0; k <= log[j]; ++k)
                    if ((j >> k) & 1)
                        check[1 << k] ^= res[j];
        }
        int mistake = 0;
        for (int i = 1; i < n; ++i)
            if (log[i] > log[i - 1])
                mistake |= i * (check[i] ^ res[i]);
        res[mistake] ^= 1;
        for (int i = 1; i < n; ++i)
            if (log[i] <= log[i - 1])
                cout << res[i];
        cout << '\n';
    }
}