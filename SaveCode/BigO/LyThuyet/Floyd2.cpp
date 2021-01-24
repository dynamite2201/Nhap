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
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dist(n, vector<int>(n, INF)); // Cho tất cả thành INF
    for (int i = 0; i < n; i++) dist[i][i] = 0; // i->i w = 0

    for (int u, v, w, i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
    }

    floydWarshall(dist, n);
    return 0;
}