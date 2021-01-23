#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
const int INF = (int) 2e9 + 22011995;

vector<int> dist;
vector<int> path;
vector<vector<pii>> adj;  // first is node, second is cost
int n, m, q;

pair<int, int> dijkstra(int s) {
    dist.assign(n, INF);
    path.assign(n, -1);

    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty()) {
        pii tmp = pq.top();
        pq.pop();

        int u = tmp.second;
        if (tmp.first != dist[u]) continue;
        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                path[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    // big là khoảng cách lớn nhất theo shorted path
    // cnt là các điểm P thỏa mãn s->P = big
    int cnt = 0;
    int big = -1;
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            continue;
        if (dist[i] == big) {
            cnt++;
        } else if (dist[i] > big) {
            big = dist[i];
            cnt = 1;
        }
    }
    return make_pair(big, cnt);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    cin >> n >> m >> q;
    adj.assign(n, vector<pii>());
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        // Nếu đồ thị vô hướng
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    while (q--) {
        int x;
        cin >> x;
        pair<int, int> g = dijkstra(x);
        cout << g.first << " " << g.second << "\n";
    }

    return 0;
}