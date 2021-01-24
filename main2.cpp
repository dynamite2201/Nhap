//
// Created by alex on 23/01/2021.
//

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
const int INF = (int) 1000000;

vector<vi> dist;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (true) {

        int n, m, q;
        cin >> n >> m >> q;
        if (n == 0 && m == 0 && q == 0) break;

        vector<vi> matrix(n, vi(n, INF));
        for (int u, v, w, i = 0; i < m; ++i) {
            cin >> u >> v >> w;
            matrix[u][v] = w;
        }

        dist.assign(n, vi(n));
        for (int i = 0; i <= n - 1; ++i) {
            for (int j = 0; j <= n - 1; ++j) {
                if (i == j) {
                    if (matrix[i][j] != INF)
                        dist[i][j] = matrix[i][j];
                    else
                        dist[i][j] = 0;
                } else {
                    dist[i][j] = matrix[i][j];
                }
            }
        }

        for (int k = 0; k <= n - 1; ++k) {
            for (int i = 0; i <= n - 1; ++i) {
                if (dist[i][k] >= INF) continue;
                for (int j = 0; j <= n - 1; ++j) {
                    if (dist[k][j] < INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

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

        for (int i = 1; i <= q; ++i) {
            int start, end;
            cin >> start >> end;
            if (dist[start][end] == INF) {
                cout << "Impossible";
            } else {
                if (dist[start][end] == -INF) {
                    cout << "-Infinity";
                } else {
                    cout << (start == end ? 0 : dist[start][end]);
                }
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}