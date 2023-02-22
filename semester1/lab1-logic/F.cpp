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

struct Clause {
    set<pii> s;
    int id = -1;
    bool operator <(const Clause &scnd) const {
        if (s.size() != scnd.s.size())
            return s.size() < scnd.s.size();
        return id < scnd.id;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    set<Clause> f;
    for (int i = 0; i < k; ++i) {
        Clause tmp;
        tmp.id = i;
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            if (x != -1)
                tmp.s.insert({ j, x });
        }
        f.insert(tmp);
    }
    while (!f.empty() && f.begin()->s.size() == 1) {
        pii p = *(f.begin()->s.begin());
        f.erase(f.begin());
        set<Clause> tmp;
        for (auto it = f.begin(); it != f.end(); ++it) {
            if (it->s.count(p)) {
                continue;
            } else if (it->s.count({ p.first, !p.second })) {
                Clause tmp2 = *it;
                tmp2.s.erase({ p.first, !p.second });
                if (tmp2.s.empty()) {
                    cout << "YES\n";
                    return;
                }
                tmp.insert(tmp2);
            } else {
                tmp.insert(*it);
            }
        }
        f = tmp;
    }
    cout << "NO\n";
}