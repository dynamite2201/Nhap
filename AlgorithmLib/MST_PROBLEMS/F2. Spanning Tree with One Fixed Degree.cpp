//
// Created by alex on 19/02/2021.
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


class UnionFind {
private:
    vi p, rank, setSize;
    int numSets;
public:
    explicit UnionFind(int N) {
        p.assign(N + 1, 0);
        for (int i = 1; i <= N; ++i) p[i] = i;
        rank.assign(N + 1, 0);
        setSize.assign(N + 1, 1);
        numSets = N;
    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }

    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) swap(x, y);
        p[x] = y;
        if (rank[x] == rank[y]) ++rank[y];
        setSize[y] += setSize[x];
        --numSets;
    }

    int numDisjointSets() const { return numSets; }

    int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int V, E, D;
    cin >> V >> E >> D;
    vector<pi> EL(E);
    vector<pi> ST;
    vector<pi> ST2;
    set<int> mySet;
    int degreeOfFirst = 0;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        if (u == 1) {
            degreeOfFirst++;
        }
        if (v == 1) {
            degreeOfFirst++;
        }
        if (u > v) swap(u, v);
        EL[i] = {u, v};
    }
    db(D, degreeOfFirst);
    if (D > degreeOfFirst) {
        cout << "NO";
        return 0;
    } else {
        sort(EL.begin(), EL.end());
        db(EL);
        int num_taken = 0;
        UnionFind UF(V);
        for (int i = 0; i < E; ++i) {
            auto[u, v] = EL[i];
            if (u == 1) continue;
            if (UF.isSameSet(u, v)) continue;
            UF.unionSet(u, v);
            ST.emplace_back(u, v);
            ++num_taken;
            if (num_taken == V - 1) break;
        }
        db(ST);
        int numSets = UF.numDisjointSets() - 1;
        db(numSets);
        UnionFind UF2(V);
        int num_taken2 = 0;
        if (numSets > D) {
            cout << "NO";
        } else {
            for (int i = 0; i < E; ++i) {
                auto[u, v] = EL[i];
                if (u != 1) continue;
                db(u, v);
                int k = UF.findSet(v);
                db(k);
                int temp = mySet.size();
                mySet.insert(k);
                if (mySet.size() == temp + 1) {
                    UF2.unionSet(1, v);
                    ST2.emplace_back(1, v);
                    D--;
                    num_taken2++;
                }
                if (num_taken2 == V - 1) break;
                if (D <= 0) continue;
            }
            db(mySet);
            db(ST2);
            db(D);
            for (int i = 0; i < E; ++i) {
                auto[u, v] = EL[i];
                db(u, v);
                if (UF2.isSameSet(u, v)) continue;
                if (u == 1 && D == 0) continue;
                if (u == 1 && D > 0) D--;
                db(u, v);
                UF2.unionSet(u, v);
                ST2.emplace_back(u, v);
                ++num_taken2;
                if (num_taken2 == V - 1) break;
            }
            db(num_taken);
            db(D);
            if (D == 0 and num_taken2 == V - 1) {
                cout << "YES" << "\n";
                for (auto &e: ST2) {
                    cout << e.first << " " << e.second << "\n";
                }
            } else {
                cout << "NO";
            }
        }
    }
    return 0;
}

// https://codeforces.com/contest/1133/problem/F2