#include <bits/stdc++.h>
#include<iostream>
#include <vector>
#include <string>
#include<queue>
#include<stack>

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

const int N = 1e6 + 1000;
const int oo = 1e9;

struct service {
    long long int id;
    long long int a;
    long long int b;
    long long int c;
};


service services[N];
service servicesCompess[N];
int numCover[N];
long long int sum[N] = {0};
vector<int> specialPoint;
vector<pair<int, int>> coordinate;

int convert(int x) {
    return (lower_bound(coordinate.begin(), coordinate.end(), make_pair(x, numeric_limits<int>::min())) -
            coordinate.begin());
}

bool isValid(int i, int l, int r) {
    if (l <= i && i <= r)return true;
    return false;
}

bool cmp(service a, service b) {
    return a.a < b.a;
}

bool check(int l, int r) {
    int lIndex = lower_bound(specialPoint.begin(), specialPoint.end(), l) - specialPoint.begin();
    int rIndex = upper_bound(specialPoint.begin(), specialPoint.end(), r) - specialPoint.begin();
    if (lIndex == specialPoint.size()) {
        return true;
    }
    if (rIndex == 0) {
        return true;
    }
    if (lIndex == rIndex)return true;
    return false;
}

void run_case() {
    long long int n, C;
    cin >> n >> C;

    for (int i = 1; i <= n; ++i) {
        cin >> services[i].a >> services[i].b >> services[i].c;
        coordinate.push_back(make_pair(services[i].a, 1));
        coordinate.push_back(make_pair(services[i].b, 0));
        assert(services[i].a <= services[i].b);
    }
    sort(coordinate.begin(), coordinate.end());
//    coordinate.resize(unique(coordinate.begin(), coordinate.end()) - coordinate.begin());
    db(coordinate);
    //Calculate number segment cover

    for (int i = 1; i <= n; i++) {
        servicesCompess[i].a = convert(services[i].a);
        servicesCompess[i].b = convert(services[i].b);


        numCover[servicesCompess[i].a]++;
        sum[servicesCompess[i].a] += services[i].c;
        numCover[servicesCompess[i].b + 1]--;
        sum[servicesCompess[i].b + 1] -= services[i].c;
        db(services[i].a, services[i].b, servicesCompess[i].a, servicesCompess[i].b, services[i].c);

    }
    int numPoint = coordinate.size();

    for (int i = 0; i < numPoint; i++) {
        db(i, sum[i]);
    }
    for (int i = 0; i < numPoint; i++) {
        db(i, numCover[i]);
        db(i, sum[i]);
    }
    db(numPoint);
    for (int i = 1; i < numPoint; i++) {
        numCover[i] += numCover[i - 1];
        sum[i] += sum[i - 1];

    }
    for (int i = 0; i < numPoint; i++) {
        db(i, numCover[i]);
        db(i, sum[i]);
    }
    long long int total = 0;
    for (int i = 0; i + 1 < numPoint; i++) {
        if (coordinate[i].second == 0 and coordinate[i + 1].second == 1) {
            total += (coordinate[i + 1].first - coordinate[i].first) * min(min(C, sum[i]), sum[i + 1]);
        }
        // TODO làm sao tính được sum tại các vị trí ở giữa, Chứ không phải đầu mút.
        // TODO nếu các đoạn thẳng overlap có trọng số, làm sao tính trọng số ko phải đầu mút.
    }
//    total += min(C, sum[numPoint-1])* (coordinate[i] - coordinate[i-1])
    for (int i = 1; i + 2 < numPoint; i++) {
        db(i, sum[i], C);
//        db(coordinate[i], coordinate[i + 1]);
    }
//    total += (coordinate[1] - coordinate[0]) * min(C, sum[0]);
//    total += (coordinate[numPoint - 1] - coordinate[numPoint - 2]) * min(C, sum[numPoint - 1]);
    db(total);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
//    cin >> T;
    T = 1;
    while (T-- > 0) {
        run_case();
    }
}
