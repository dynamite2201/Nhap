#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << '{';
    string sep;
    for (const auto &x : v) os << sep << x, sep = ", ";
    return os << '}';
}

template<typename T, size_t size>
ostream &operator<<(ostream &os, const array<T, size> &arr) {
    os << '{';
    string sep;
    for (const auto &x : arr) os << sep << x, sep = ", ";
    return os << '}';
}

template<typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }

template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
    cerr << ' ' << H;
    dbg_out(T...);
}

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


void run_case() {
    int N, K;
    cin >> N >> K;
    vector<int> X(N), Y(N);

    for (int i = 0; i < N; i++)
        cin >> X[i] >> Y[i];

    bool possible = false;

    for (int base = 0; base < N; base++) {
        bool good = true;

        for (int i = 0; i < N; i++)
            if (abs(X[i] - X[base]) + abs(Y[i] - Y[base]) > K)
                good = false;

        possible = possible || good;
    }

    cout << (possible ? 1 : -1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}
