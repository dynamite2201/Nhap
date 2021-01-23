//
// Created by alex on 17/01/2021.
// https://bigocoder.com/courses/45/lectures/649/problems/1187?view=statement

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

int test = 1;

void run_case() {
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<>> pq;
    vector<priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<>>> pqAval(2);
    int T, NA, NB;
    cin >> T >> NA >> NB;
    int res[2];
    res[0] = 0, res[1] = 0;
    for (int i = 0; i < NA; ++i) {
        string start, end;
        cin >> start >> end;
        int x = start[0] - '0';
        int y = start[1] - '0';
        int z = start[3] - '0';
        int t = start[4] - '0';
        int timestart = (10 * x + y) * 60 + 10 * z + t;
        x = end[0] - '0';
        y = end[1] - '0';
        z = end[3] - '0';
        t = end[4] - '0';
        int timesend = (10 * x + y) * 60 + 10 * z + t;
        pair<pair<int, int>, int> trip = make_pair(make_pair(timestart, timesend), 0);
        pq.push(trip);
    }
    for (int i = 0; i < NB; ++i) {
        string start, end;
        cin >> start >> end;
        int x = start[0] - '0';
        int y = start[1] - '0';
        int z = start[3] - '0';
        int t = start[4] - '0';
        int timestart = (10 * x + y) * 60 + 10 * z + t;
        x = end[0] - '0';
        y = end[1] - '0';
        z = end[3] - '0';
        t = end[4] - '0';
        int timesend = (10 * x + y) * 60 + 10 * z + t;
        pair<pair<int, int>, int> trip = make_pair(make_pair(timestart, timesend), 1);
        pq.push(trip);
    }

    while (!pq.empty()) {
        pair<pair<int, int>, int> mostTrip = pq.top();
        if (!pqAval[mostTrip.second].empty() && pqAval[mostTrip.second].top() <= mostTrip) {
            pqAval[mostTrip.second].pop();
        } else {
            res[mostTrip.second]++;
        }
        pq.pop(); //  den noi
        // Them chuyen o tram doi dien:
        int timeStart = mostTrip.first.second + T;
        int interval = mostTrip.first.second - mostTrip.first.first;
        if (timeStart <= 23 * 60 + 59) {
            pair<pair<int, int>, int> tripAdded = make_pair(make_pair(timeStart, timeStart + interval),
                                                            1 - mostTrip.second);
            pqAval[1 - mostTrip.second].push(tripAdded);
        }
    }

    cout << "Case #" << test << ": " << res[0] << " " << res[1] << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while (T > 0) {
        run_case();
        T--;
        test++;
    }
}
