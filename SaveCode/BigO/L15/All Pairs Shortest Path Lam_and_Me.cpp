//
// Created by alex on 24/01/2021.
//

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
const int maxN = 150, maxW = 1000;
const int INF = (maxN - 1) * maxW;


void floydWarshall(vector<vector<int>> &dist, int n) {
    for (int k = 0; k <= n - 1; ++k) {
        for (int i = 0; i <= n - 1; ++i) {
            if (dist[i][k] >= INF) continue;
            for (int j = 0; j <= n - 1; ++j) {
                if (dist[k][j] < INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    dist[i][j] = max(dist[i][j], -1 * INF);
                }
            }
        }
    }
    for (int k = 0; k <= n - 1; ++k) {
        for (int i = 0; i <= n - 1; ++i) {
            if (dist[i][k] >= INF) continue;
            for (int j = 0; j <= n - 1; ++j) {
                if (dist[k][j] < INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = -1 * INF;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (true) {
        int n, m, q;
        cin >> n >> m >> q;
        if (n == 0 && m == 0 && q == 0) break;
        vector<vi> dist(n, vi(n, INF));
        for (int i = 0; i < n; i++) dist[i][i] = 0;
        for (int u, v, w, i = 0; i < m; ++i) {
            cin >> u >> v >> w;
            dist[u][v] = min(dist[u][v], w);
        }

        floydWarshall(dist, n);

        for (int i = 1; i <= q; ++i) {
            int start, end;
            cin >> start >> end;
            if (dist[start][end] == INF) {
                cout << "Impossible";
            } else {
                if (dist[start][end] == -1 * INF) {
                    cout << "-Infinity";
                } else {
                    cout << dist[start][end];
                }
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}