#include <bits/stdc++.h>

using namespace std;

const int maxN = 150, maxW = 1000, minW = -1000;
const int maxINF = (maxN - 1) * maxW, minINF = (maxN - 1) * minW;

void floydWarshall2(vector<vector<int>> &dist, int n) {
    for (int k = 0; k <= n - 1; ++k) {
        for (int i = 0; i <= n - 1; ++i) {
            if (dist[i][k] >= maxINF) continue;
            for (int j = 0; j <= n - 1; ++j) {
                if (dist[k][j] < maxINF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    dist[i][j] = max(dist[i][j],
                                     minINF); // nếu không có chu trình âm -> simple path -> min all path = (n-1)*-maxW
                }
            }
        }
    }

    for (int k = 0; k <= n - 1; ++k) {
        for (int i = 0; i <= n - 1; ++i) {
            if (dist[i][k] >= maxINF) continue;
            for (int j = 0; j <= n - 1; ++j) {
                if (dist[k][j] < maxINF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = minINF;
                }
            }
        }
    }

}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dist(n, vector<int>(n, maxINF)); // Cho tất cả thành maxINF.
    for (int i = 0; i < n; i++) dist[i][i] = 0; // i->i w = 0.

    for (int u, v, w, i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w); // nếu là multigraph chọn cạnh nhỏ nhất.
    }

    floydWarshall2(dist, n);
    return 0;
}