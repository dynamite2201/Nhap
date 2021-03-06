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


int convert(vector<int> &arr, int x) {
    return (lower_bound(arr.begin(), arr.end(), x) - arr.begin());
}

vector<pair<int, int>> countOccurrences(vector<int> &arr) {
    vector<pair<int, int>> cntcnt;
    for (int i = 0; i < arr.size(); ++i) {
        int temp2 = arr[i];
        int index2 = i;
        int count2 = 0;
        while (temp2 == arr[index2] && index2 < arr.size()) {
            count2++;
            index2++;
        }
        cntcnt.emplace_back(temp2, count2);
        i = index2 - 1;
    }
    return cntcnt;
}

void runcase() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<int> temp = arr;
    vector<int> temp2 = arr;
    sort(temp.begin(), temp.end());
    temp.resize(unique(temp.begin(), temp.end()) - temp.begin());
    for (int i = 0; i < n; ++i) {
        arr[i] = convert(temp, arr[i]);
    }

    sort(arr.begin(), arr.end());
    vector<int> arr2 = arr;
    arr.resize(unique(arr.begin(), arr.end()) - arr.begin());
    db(temp2); // day ban dau
    db(arr2); // day ban dau roi rac hoa
    db(temp); // day nen
    db(arr); // day nen roi rac hoa, luon co dang 0,1,2,3,4....
    map<int, ll> myMap;
    for (int i = 0; i < arr.size(); ++i) {
        myMap[i] = temp[i];
    }
    db(myMap);
    vector<pair<int, int>> cntOcc = countOccurrences(arr2);
    sort(cntOcc.begin(), cntOcc.end());
    db(cntOcc);
    map<int, ll> mySumMap;
    for (int i = 0; i < arr.size(); ++i) {
        mySumMap[i] = myMap[i] * cntOcc[i].second;
    }
    db(mySumMap);
    vector<long long int> prefixSum(arr.size());
    for (int i = 0; i < arr.size(); ++i) {
        prefixSum[i] = mySumMap[i];
    }

    vector<long long int> originalPrefixSum = prefixSum;
    for (int i = 0; i < arr.size() - 1; ++i) {
        prefixSum[i + 1] += prefixSum[i];
    }
    db(originalPrefixSum);
    db(prefixSum);
    db(arr.size());
    vector<long long int> good;
    good.push_back(temp[arr.size() - 1]);
    for (int i = arr.size() - 2; i >= 0; i--) {
        if (prefixSum[i] >= temp[i + 1]) {
            good.push_back(temp[i]);
        } else {
            break;
        }
    }

    sort(good.begin(), good.end());
    db(good);
    vector<int> goodIndex;
    vector<pair<int, int>> arrAndIndex;
    for (int i = 0; i < temp2.size(); ++i) {
        arrAndIndex.emplace_back(temp2[i], i);
    }
    sort(arrAndIndex.begin(), arrAndIndex.end());
    db(arrAndIndex);
    int index = 0;
    for (int i = 0; i < arrAndIndex.size(); ++i) {
        if (arrAndIndex[i].first > good[index]) index++;
        if (arrAndIndex[i].first == good[index]) {
            goodIndex.push_back(arrAndIndex[i].second);
        }
    }
    db(goodIndex);
    sort(goodIndex.begin(), goodIndex.end());
    cout << goodIndex.size() << "\n";
    for (int i = 0; i < goodIndex.size(); ++i) {
        cout << goodIndex[i] + 1 << " ";
    }
    cout << "\n";
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        runcase();
    }
    return 0;
}