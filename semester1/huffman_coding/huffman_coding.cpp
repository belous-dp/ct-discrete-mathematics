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

/*-------------------------------------------------------------------------------------------------------------*/

constexpr int K = 2;

struct Node {
    bool term;
    int sum;
    string c;
    vector<pii> to;
    Node(bool term_ = false, int sum_ = 0, string c_ = "", vector<pii> to_ = vector<pii>(0)) :
        term(term_), sum(sum_), c(c_), to(to_) {
    }
};

vector<Node> trie;
map<string, string> coding;

void dfs(int v, string &path) {
    //cout << v << ' ';
    if (trie[v].term) {
        cout << trie[v].c << ' ' << path << '\n';
        coding[trie[v].c] = path;
    }
    //for (pii u : trie[v].to)
        //cout << '(' << u.first << ' ' << u.second << ") ";
    //cout << '\n';
    for (pii u : trie[v].to) {
        path += to_string(u.second);
        dfs(u.first, path);
        path.pop_back();
    }
}

struct Token {
    string token;
    int codingLen, freq;
    Token(string token_ = "", int codingLen_ = 0, int freq_ = 0) :
        token(token_), codingLen(codingLen_), freq(freq_) {
    }
    bool operator <(const Token &other) const {
        return freq > other.freq;
    }
};

void solve() {
    int n = 0;
    cin >> n;
    vector<pair<int, string>> fr(n);
    map<string, int> inputMap;
    for (auto &i : fr) {
        cin >> i.second >> i.first;
        inputMap[i.second] = i.first;
    }
    sort(all(fr));
    vector<pii> sumFr(n, { INF, -1 });
    trie.resize(4 * n);
    int triesz = 0, sumfrsz = 0;
    for (int i = 0, p1 = 0, p2 = 0; i < n - 1; ++i) {
        vector<int> nodeId;
        for (int j = 0; j < K && (p1 < n || p2 < sumfrsz); ++j) {
            if (p1 < n && (p2 >= sumfrsz || fr[p1].first < sumFr[p2].first)) {
                trie[triesz] = Node(true, fr[p1].first, fr[p1].second);
                nodeId.push_back(triesz++);
                p1++;
            } else {
                nodeId.push_back(sumFr[p2++].second);
            }
        }
        trie[triesz] = Node();
        for (int j = 0; j < nodeId.size(); ++j) {
            trie[triesz].sum += trie[nodeId[j]].sum;
            trie[triesz].to.push_back({ nodeId[j], j });
        }
        sumFr[sumfrsz++] = { trie[triesz].sum, triesz };
        triesz++;
    }
    string path;
    dfs(triesz - 1, path);
    ll prod = 1;
    ll lg = 0;
    while (prod < n) {
        lg++;
        prod *= K;
    }
    ll clcs = lg * sumFr[sumfrsz - 1].first;
    cout << "constant length coding size: " << clcs << '\n';
    cout << "huffman coding size: ";
    ll res = 0;
    for (auto i : inputMap)
        res += (ll)coding[i.first].length() * i.second;
    cout << res << '\n';
    cout << "huffman is better " << fixed << setprecision(3) <<
        (ld)(clcs) / res << " times\n";

    vector<Token> v;
    for (auto i : inputMap)
        v.push_back({ i.first, (int)coding[i.first].length(), i.second });
    sort(all(v));
    for (Token &i : v) {
        cout << i.token << ": " << i.codingLen << ' ' << i.freq << '\n';
    }
}