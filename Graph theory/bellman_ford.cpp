#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Edge {
    int u, v, w;
};

bool bellmanFord(int n, int src, vector<Edge>& edges, vector<int>& dist) {
    dist.assign(n, INF);
    dist[src] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (auto edge : edges) {
            if (dist[edge.u] < INF) {
                dist[edge.v] = min(dist[edge.v], dist[edge.u] + edge.w);
            }
        }
    }

    for (auto edge : edges) {
        if (dist[edge.u] < INF && dist[edge.u] + edge.w < dist[edge.v]) {
            return false;
        }
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector <Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int src;
    cin >> src;

    vector<int> dist;
    if (bellmanFord(n, src, edges, dist)) {
        for (int i = 0; i < n; ++i) {
            if (dist[i] == INF) cout << "INF ";
            else cout << dist[i] << " ";
        }
    }
    else cout << "Negative weight cycle detected.\n";

    return 0;
}
