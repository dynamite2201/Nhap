//
// Created by alex on 23/01/2021.
//

#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

#define x first
#define y second

typedef long long li;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);

int n;
vector<int> a;

inline bool read() {
    if (!(cin >> n))
        return false;
    a.resize(n);
    fore (i, 0, n)cin >> a[i];
    return true;
}

inline void solve() {
    vector<int> h(n, INF);
    // h[i] là độ sâu của a[i]
    h[0] = 0; // độ sâu của root
    int lst = 0; // lưu các độ sâu "KHÁC NHAU", tức là độ sâu của các Parent.
    fore (i, 1, n) {
        if (i - 1 > 0 && a[i - 1] > a[i])
            lst++; // Hết 1 đoạn tăng, phải lấy 1 child ở dưới làm parent kêt tiếp
        h[i] = h[lst] + 1; // độ sâu của nút child = độ sâu parent + 1
    }
    cout << h[n - 1] << endl;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    int tt = clock();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int tc;
    cin >> tc;
    while (tc--) {
        read();
        solve();

#ifdef _DEBUG
        cerr << "TIME = " << clock() - tt << endl;
        tt = clock();
#endif
    }
    return 0;
}