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
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    vector<string> m;
    for (int i = 0; i < 26; ++i) {
        char c = i + 'a';
        string tmp;
        tmp += c;
        m.push_back(tmp);
    }
    string t;
    for (int i = 0; i < n; ++i) {
        if (!t.empty()) {
            if (v[i] >= m.size())
                t += t[0];
            else
                t += m[v[i]][0];
            m.push_back(t);
        }
        t = m[v[i]];
        cout << t;
    }
    cout << '\n';
}