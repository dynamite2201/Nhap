#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
const int INF = (int) 2e9 + 22011995;

vector<int> dist;
vector<int> path;
vector<vector<pii>> adj;
int n, m;

void dijkstra(int s) {
    dist.assign(n + 1, INF);
    path.assign(n + 1, -1);

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
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    cin >> n >> m;
    adj.assign(n + 1, vector<pii>());
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dijkstra(1);
    if (dist[n] == INF) {
        cout << -1;
    } else {
        stack<int> st;
        int res = n;

        while (res != 1) {
            st.push(res);
            res = path[res];
        }
        st.push(1);
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
    }
}