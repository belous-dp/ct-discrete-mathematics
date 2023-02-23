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

#define TASK "check"
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
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q = 1;
    if (multi_test) cin >> q;
    while (q--) solve();
}

/*-------------------------------------------------------------------------------------------------------*/

bool contains(set<int> const& s, int elem) {
    // please add C++20 to PCMS
    return s.find(elem) != s.end();
}

void solve() {
    int n, m;
    cin >> n >> m;
    set<int> s; // set of masks (sets)
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        int set = 0;
        for (int j = 0; j < k; ++j) {
            int elem;
            cin >> elem;
            set += 1 << (elem - 1);
        }
        s.insert(set);
    }
    // 1st axiom:
    if (!contains(s, 0)) {
        cout << "NO\n";
        return;
    }
    // 2nd axiom:
    for (int a : s) {
        int b = a;
        while (b > 0) { // submask
            b = (b - 1) & a;
            if (!contains(s, b)) {
                cout << "NO\n";
                return;
            }
        }
    }
    // 3rd axiom:
    for (int a : s) {
        int ca = __builtin_popcount(a);
        for (int b : s) {
            int cb = __builtin_popcount(b);
            if (ca > cb) {
                int mask = (a ^ b) & a;
                bool ok = false;
                for (int i = 0; i < n; ++i) {
                    if ((mask & (1 << i)) > 0 && contains(s, b | (1 << i))) {
                        ok = true;
                        break;
                    }
                }
                if (!ok) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
}