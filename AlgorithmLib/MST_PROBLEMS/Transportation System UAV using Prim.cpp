//
// Created by alex on 04/02/2021.
//
#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <string>
#include <bitset>

using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define present(t, x) (t.find(x) != t.end())
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
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef pair<ll, ll> pll;
typedef vector<pair<ll, ll>> vpll;
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


double roadLength, railLength;
const int MAX = 1e4 + 5;
typedef pair<double, int> PII;
bool marked[MAX];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    db("Hello");
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        for (int j = 0; j < MAX; ++j) {
            marked[j] = false;
        }
        vector<PII> adj[MAX];
        int V, r;
        cin >> V >> r;
        vector<pair<int, pii>> Vertex;
        for (int j = 0; j < V; ++j) {
            int x, y;
            cin >> x >> y;  // Tọa độ
            Vertex.push_back({j, {x, y}}); // Id, tọa độ
        }
        for (int j = 0; j < V; ++j) {
            for (int k = 0; k < V; ++k) {
                if (Vertex[j].first == Vertex[k].first) continue; //  2 đỉnh trùng
                int u = Vertex[j].first;
                int v = Vertex[k].first;
                int xu = Vertex[j].second.first;
                int yu = Vertex[j].second.second;
                int xv = Vertex[k].second.first;
                int yv = Vertex[k].second.second;
                double length = sqrt((xu - xv) * (xu - xv) + (yu - yv) * (yu - yv));
                adj[u].emplace_back(length, v);
                db(u, v, length);
            }
        }

        roadLength = 0;
        railLength = 0;
        int numStates = 0;
        priority_queue<PII, vector<PII>, greater<> > Q;
        int y;

        PII p;
        int x = 0;
        int count = 0;
        Q.push(make_pair(0, x));
        while (!Q.empty()) {
            // Select the edge with minimum weight
            p = Q.top();
            Q.pop();
            x = p.second;
            // Checking for cycle
            if (marked[x])
                continue;
            if (p.first <= r) {
                roadLength += p.first;
                db(p.first, x);
            } else {
                railLength += p.first;
                numStates++;
            }
            marked[x] = true;
            count++;
            for (auto &edge : adj[x]) {
                y = edge.second;
                if (!marked[y])
                    Q.push(edge);
            }
            if (count == V) break;
        }
        numStates++;
        cout << "Case #" << i << ": " << numStates << " " << round(roadLength) << " "
             << round(railLength) << "\n";
    }
    return 0;
}



// https://codeforces.com/problemset/problem/1081/D
