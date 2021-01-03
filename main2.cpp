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


void run_case(int test) {
    int number[10] = {0};
    int characters[26] = {0};
    string S;
    cin >> S;
//    cin.ignore();
//    getline(cin, S);
    string res = "";

    db(S);
    for (int i = 0; i < S.length(); ++i) {
        characters[S[i] - 'A']++;
    }

    while (characters['Z' - 'A'] > 0) {
        characters['Z' - 'A']--;
        characters['E' - 'A']--;
        characters['R' - 'A']--;
        characters['O' - 'A']--;
        number[0]++;
    }
    while (characters['W' - 'A'] > 0) {
        characters['T' - 'A']--;
        characters['W' - 'A']--;
        characters['O' - 'A']--;
        number[2]++;
    }
    while (characters['X' - 'A'] > 0) {
        characters['S' - 'A']--;
        characters['I' - 'A']--;
        characters['X' - 'A']--;
        number[6]++;
    }
    while (characters['G' - 'A'] > 0) {
        characters['E' - 'A']--;
        characters['I' - 'A']--;
        characters['G' - 'A']--;
        characters['H' - 'A']--;
        characters['T' - 'A']--;
        number[8]++;
    }
    while (characters['U' - 'A'] > 0) {
        characters['F' - 'A']--;
        characters['O' - 'A']--;
        characters['U' - 'A']--;
        characters['R' - 'A']--;
        number[4]++;
    }
    while (characters['F' - 'A'] > 0) {
        characters['F' - 'A']--;
        characters['I' - 'A']--;
        characters['V' - 'A']--;
        characters['E' - 'A']--;
        number[5]++;
    }
    while (characters['V' - 'A'] > 0) {
        characters['V' - 'A']--;
        characters['S' - 'A']--;
        characters['E' - 'A']--;
        characters['E' - 'A']--;
        characters['N' - 'A']--;
        number[7]++;
    }
    while (characters['R' - 'A'] > 0) {
        characters['R' - 'A']--;
        characters['T' - 'A']--;
        characters['H' - 'A']--;
        characters['E' - 'A']--;
        characters['E' - 'A']--;
        number[3]++;
    }
    while (characters['O' - 'A'] > 0) {
        characters['O' - 'A']--;
        characters['N' - 'A']--;
        characters['E' - 'A']--;
        number[1]++;
    }
    while (characters['I' - 'A'] > 0) {
        characters['I' - 'A']--;
        characters['N' - 'A']--;
        characters['N' - 'A']--;
        characters['E' - 'A']--;
        number[9]++;
    }
    for (int i = 0; i < 10; ++i) {
        while (number[i] > 0) {
            res += to_string(i);
            number[i]--;
        }
    }


//    cout << "Case #" << test + 1 << ": " << "Too Bad" << "\n";
    cout << "Case #" << test + 1 << ": " << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int tests;
    cin >> tests;
    int i = 0;
    while (i < tests) {
        run_case(i);
        i++;
    }
}
