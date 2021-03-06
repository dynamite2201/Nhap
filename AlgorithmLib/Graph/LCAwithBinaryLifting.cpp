//
// Created by alex on 07/03/2021.
//

#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int FFTMOD = 119 << 23 | 1;
const int INF = (int) 2e9 + 22011995;
const ll LINF = (ll) 9e18 + 22011995;
const ld PI = acos((ld) -1);
const ld EPS = 1e-6;

inline ll gcd(ll a, ll b) {
    ll r;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

inline ll fpow(ll n, ll k, int p = MOD) {
    ll r = 1;
    for (; k; k >>= 1) {
        if (k & 1) r = r * n % p;
        n = n * n % p;
    }
    return r;
}

template<class T>
inline int chkmin(T &a, const T &val) { return val < a ? a = val, 1 : 0; }

template<class T>
inline int chkmax(T &a, const T &val) { return a < val ? a = val, 1 : 0; }

inline ull isqrt(ull k) {
    ull r = sqrt(k) + 1;
    while (r * r > k) r--;
    return r;
}

inline ll icbrt(ll k) {
    ll r = cbrt(k) + 1;
    while (r * r * r > k) r--;
    return r;
}

inline void addmod(int &a, int val, int p = MOD) { if ((a = (a + val)) >= p) a -= p; }

inline void submod(int &a, int val, int p = MOD) { if ((a = (a - val)) < 0) a += p; }

inline int mult(int a, int b, int p = MOD) { return (ll) a * b % p; }

inline int inv(int a, int p = MOD) { return fpow(a, p - 2, p); }

inline int sign(ld x) { return x < -EPS ? -1 : x > +EPS; }

inline int sign(ld x, ld y) { return sign(x - y); }

mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());

inline int mrand() { return abs((int) mt()); }

inline int mrand(int k) { return abs((int) mt()) % k; }

void __print(int x) { cerr << x; }

void __print(long x) { cerr << x; }

void __print(long long x) { cerr << x; }

void __print(unsigned x) { cerr << x; }

void __print(unsigned long x) { cerr << x; }

void __print(unsigned long long x) { cerr << x; }

void __print(float x) { cerr << x; }

void __print(double x) { cerr << x; }

void __print(long double x) { cerr << x; }

void __print(char x) { cerr << '\'' << x << '\''; }

void __print(const char *x) { cerr << '\"' << x << '\"'; }

void __print(const string &x) { cerr << '\"' << x << '\"'; }

void __print(bool x) { cerr << (x ? "true" : "false"); }

template<typename T, typename V>
void __print(const pair<T, V> &x) {
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}

template<typename T>
void __print(const T &x) {
    int f = 0;
    cerr << '{';
    for (auto &i: x) cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}

void _print() { cerr << "]\n"; }

template<typename T, typename... V>
void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v)) cerr << ", ";
    _print(v...);
}

#ifndef ONLINE_JUDGE
#define db(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define db(x...)
#endif

class UnionFind {                                // OOP style
private:
    vi p, rank, setSize;                           // vi p is the key part
    int numSets;
public:
    UnionFind(int N) {
        p.assign(N + 1, 0);
        for (int i = 1; i <= N; ++i) p[i] = i;
        rank.assign(N + 1, 0);                           // optional speedup
        setSize.assign(N + 1, 1);                        // optional feature
        numSets = N;                                 // optional feature
    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }

    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;                 // i and j are in same set
        int x = findSet(i), y = findSet(j);          // find both rep items
        if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
        p[x] = y;                                    // set x under y
        if (rank[x] == rank[y]) ++rank[y];           // optional speedup
        setSize[y] += setSize[x];                    // combine set sizes at y
        --numSets;                                   // a union reduces numSets
    }

    int numDisjointSets() { return numSets; }

    int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

struct edge {
    int s, e, w, id;

    bool operator<(const struct edge &other) { return w < other.w; }
};

typedef struct edge Edge;

const int N = 2e5 + 5;
long long res = 0;
vector<long long> ans(N, 1e18);
int n, m, a, b, w, id, l = 21;
vector<Edge> edges;
vector<int> h(N, 0), parent(N, -1), present(N, 0);
vector<vector<pair<int, int>>> adj(N), dp(N, vector<pair<int, int>>(l));
vector<vector<int>> up(N, vector<int>(l, -1));

pair<int, int> combine(pair<int, int> a, pair<int, int> b) { // hàm trả về lớn nhất và lớn nhì của 2 bộ.
    vector<int> v = {a.first, a.second, b.first, b.second};
    int topTwo = -3, topOne = -2;
    for (int c : v) {
        if (c >= topOne) {
            topTwo = topOne;
            topOne = c;
        } else if (c >= topTwo && c < topOne) {
            topTwo = c;
        }
    }
    return {topOne, topTwo};
}

void dfs(int u, int par, int d) {
    h[u] = 1 + h[par];
    up[u][0] = par;
    dp[u][0] = {d, -1};
    for (auto v : adj[u]) {
        if (v.first != par) {
            dfs(v.first, u, v.second);
        }
    }
}

pair<int, int> lca(int u, int v) {
    pair<int, int> topNsecond = {-2, -3};
    if (h[u] < h[v]) {
        swap(u, v);
    }
    for (int i = l - 1; i >= 0; i--) {
        if (h[u] - h[v] >= (1 << i)) { // stop when h[u]==h[v] same deep
            topNsecond = combine(topNsecond, dp[u][i]);
            u = up[u][i];
        }
    }
    if (u == v) { //  v is ancestor of u
        return topNsecond;
    }
    for (int i = l - 1; i >= 0; i--) { //binary lift -> Up to gan den LCA.
        if (up[u][i] != -1 && up[v][i] != -1 && up[u][i] !=
                                                up[v][i]) { // bỏ qua các bit vượt quá LCA, chỉ xài các bit bé hơn LCA -->100010101... hợp thành sát LCA 1 nấc.
            topNsecond = combine(topNsecond, combine(dp[u][i], dp[v][i]));
            u = up[u][i];
            v = up[v][i];
        }
    }
    topNsecond = combine(topNsecond, combine(dp[u][0], dp[v][0])); // last hit to LCA.
    return topNsecond;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> w; // 1-indexed
        edges.push_back({a, b, w, i - 1});
    }
    sort(edges.begin(), edges.end());
    UnionFind UF(n);
    for (int i = 0; i <= m - 1; i++) {
        a = edges[i].s;
        b = edges[i].e;
        w = edges[i].w;
        id = edges[i].id;
        if (UF.isSameSet(a, b)) continue;
        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w);
        UF.unionSet(a, b);
        present[id] = 1;
        res += w;
    }
    dfs(1, 0, 0);
    for (int i = 1; i <= l - 1; i++) {
        for (int j = 1; j <= n; ++j) {
            if (up[j][i - 1] != -1) { // chỉ update đến node 0, vì khi up lên 2^(i-1) = -1 tức là đã up vượt quá node 0.
                int v = up[j][i - 1];
                up[j][i] = up[v][i - 1];
                dp[j][i] = combine(dp[j][i - 1], dp[v][i - 1]);
            }
        }
    }
//    db(up[0]);
//    db(up[1]);
//    db(up[2]);
//    db(up[3]);
//    db(up[4]);
//    db(up[5]);
//    db(up[6]);
//    db(up[7]);
//    db(up[8]);
//    db(up[9]);
//    db(up[10]);
//    db(up[11]);
//    db(dp[0]);
//    db(dp[1]);
//    db(dp[2]);
//    db(dp[3]);
//    db(dp[4]);
//    db(dp[5]);
//    db(dp[6]);
//    db(dp[7]);
//    db(dp[8]);
//    db(dp[9]);
//    db(dp[10]);
//    db(dp[11]);
//    db(combine({0, -1}, {0, 0}));

    for (int i = 0; i <= m - 1; i++) {
        id = edges[i].id;
        w = edges[i].w;
        if (!present[id]) {
            auto rem = lca(edges[i].s, edges[i].e);
            ans[id] = res + w - rem.first;
        } else {
            ans[id] = res;
        }
    }

    for (int i = 0; i <= m - 1; ++i) {
        cout << ans[i] << "\n";
    }

    return 0;
}