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

bool is_F_preserving(int n, const bitset<BS> &f) {
    return !f.test(0);
}

bool is_T_preserving(int n, const bitset<BS> &f) {
    return f.test((1 << n) - 1);
}

bool is_self_dual(int n, const bitset<BS> &f) {
    for (int i = 0; i < (1 << n); ++i) {
        bitset<BS> inv(i);
        for (int j = 0; j < n; ++j)
            inv.flip(j);
        if (f.test(i) == f.test(inv.to_ulong()))
            return false;
    }
    return true;
}

bool is_monotonic(int n, const bitset<BS> &f) {
    for (int i = 0; i < (1 << n); ++i)
        for (int j = i; ; j = (j - 1) & i) {
            if (!f.test(i) && f.test(j)) // j <= i && f(j) > f(i)
                return false;
            if (j == 0)
                break;
        }
    return true;
}

bool is_linear(int n, const bitset<BS> &f) {
    vector<int> res(BS);
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = i; ; j = (j - 1) & i) {
            res[i] ^= f.test(j);
            if (j == 0)
                break;
        }
        bitset<BS> b(i);
        if (res[i] && b.count() > 1)
            return false;
    }
    return true;
}

void solve() {
    int t;
    cin >> t;
    vector<int> cntPost(5);
    for (int tt = 0; tt < t; ++tt) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        reverse(all(s));
        bitset<BS> f(s);
        cntPost[0] += is_F_preserving(n, f);
        cntPost[1] += is_T_preserving(n, f);
        cntPost[2] += is_self_dual(n, f);
        cntPost[3] += is_monotonic(n, f);
        cntPost[4] += is_linear(n, f); //synonyms: affine connected; counting
    }
    for (int i = 0; i < 5; ++i)
        if (cntPost[i] == t) {
            cout << "NO\n";
            return;
        }
    cout << "YES\n";
}