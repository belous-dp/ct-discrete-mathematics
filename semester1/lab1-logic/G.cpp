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

using ui = unsigned __int32;
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

constexpr int BITSET_SIZE = 64;

void solve() {
    int n;
    cin >> n;
    vector<bitset<BITSET_SIZE>> v;
    for (int i = 0; i < n; ++i) {
        ui x;
        cin >> x;
        v.push_back(bitset<BITSET_SIZE>(x));
    }
    ui res;
    cin >> res;
    bitset<BITSET_SIZE> want(res);
    vector<int> f(BITSET_SIZE, -1);
    for (int i = 0; i < BITSET_SIZE; ++i) {
        ui res = 0;
        for (int j = 0; j < n; ++j)
            res += v[j].test(i) * (1 << j);
        if (f[res] != -1 && f[res] != want.test(i)) {
            cout << "Impossible\n";
            return;
        }
        f[res] = want.test(i);
    }
    if (!count(all(f), 1)) {
        cout << "1&~1\n";
        return;
    }
    string ans;
    for (int i = 0; i < BITSET_SIZE; ++i) {
        if (f[i] != 1)
            continue;
        ans += "(";
        for (int j = 0; j < n; ++j) {
            if (!((i >> j) & 1))
                ans += "~";
            ans += to_string(j + 1) + "&";
        }
        ans.pop_back();
        ans += ")|";
    }
    ans.pop_back();
    cout << ans << '\n';
}