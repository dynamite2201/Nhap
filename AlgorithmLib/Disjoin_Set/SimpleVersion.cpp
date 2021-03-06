//
// Chỉ có vector p và getSize tức là chỉ quan tâm đại diện của Set và cỡ của Set
// Nếu không quan tâm đến cỡ của set thì chỉ loại bỏ vector getSize, và hàm merge chỉ là:

//void merge(int u, int v) {
//    u = getp(u);
//    v = getp(v);
//    p[v] = u;
//}

// Hàm getp đã sử dụng Compress Path nhưng hàm merge không sử dụng theo union theo Rank nên cây khá là to.

// https://codeforces.com/problemset/problem/1213/G

#include <bits/stdc++.h>

using namespace std;

vector<int> p, getSize;

int getp(int v) {
    if (v == p[v]) return v;
    return p[v] = getp(p[v]);
}

long long res;

long long get(int cnt) {
    return cnt * 1ll * (cnt - 1) / 2;
}

void merge(int u, int v) {
    u = getp(u);
    v = getp(v);

    res -= get(getSize[u]);
    res -= get(getSize[v]);

    getSize[u] += getSize[v];

    res += get(getSize[u]);

    p[v] = u;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    res = 0;
    p = getSize = vector<int>(n, 1);
    iota(p.begin(), p.end(), 0);

    vector<pair<int, pair<int, int>>> e(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> e[i].second.first >> e[i].second.second >> e[i].first;
        --e[i].second.first;
        --e[i].second.second;
    }

    vector<pair<int, int>> q(m);
    vector<long long> ans(m);
    for (int i = 0; i < m; ++i) {
        cin >> q[i].first;
        q[i].second = i;
    }

    sort(e.begin(), e.end());
    sort(q.begin(), q.end());

    int pos = 0;
    for (int i = 0; i < m; ++i) {
        while (pos < n - 1 && e[pos].first <= q[i].first) {
            int u = e[pos].second.first;
            int v = e[pos].second.second;
            merge(u, v);
            ++pos;
        }
        ans[q[i].second] = res;
    }

    for (int i = 0; i < m; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}