//
// Created by alex on 24/01/2021.
//

#include <bits/stdc++.h>

using namespace std;

const int maxN = 150, maxW = 1000, minW = -1000;
const int maxINF = (maxN - 1) * maxW, minINF = (maxN - 1) * minW;

void floydWarshall2(vector<vector<int>> &dist, int n) {
    // floyd - warshal
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][j] > dist[i][k] + dist[k][j] && dist[i][k] < maxINF &&
                    dist[k][j] < maxINF) // i đến được k, k đến được j
                    dist[i][j] = dist[i][k] + dist[k][j];

    // detect negative cycles
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; dist[i][j] != minINF && k < n; k++)
                if (dist[k][k] < 0 && dist[i][k] != maxINF && dist[k][j] !=
                                                              maxINF) // i đến được k, k đến được j ( tức k nằm giữa i và j) và nếu dist[k][k] < 0 thì:
                    dist[i][j] = minINF;

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