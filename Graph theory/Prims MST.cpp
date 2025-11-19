#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; // Infinity

// Use when Graph is dense, m >= n2 / 4
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; // n = number of vertices, m = number of edges
    cin >> n >> m;

    vector<vector<int>> adj(n, vector<int>(n, INF));

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w; // 0-based vertices
        adj[u][v] = w;
        adj[v][u] = w; // because undirected graph
    }

    vector<int> key(n, INF);     // min edge weight to MST
    vector<int> parent(n, -1);   // store MST edges
    vector<bool> inMST(n, false);

    key[0] = 0; // start from vertex 0

    for (int count = 0; count < n - 1; count++) {
        // Find the vertex u not in MST with minimum key[u]
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!inMST[i] && (u == -1 || key[i] < key[u]))
                u = i;
        }

        inMST[u] = true;

        // Update keys of adjacent vertices
        for (int v = 0; v < n; v++) {
            if (adj[u][v] < key[v] && !inMST[v]) {
                key[v] = adj[u][v];
                parent[v] = u;
            }
        }
    }

    // Print MST
    cout << "Edges in MST:\n";
    int totalWeight = 0;
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " : " << adj[i][parent[i]] << "\n";
        totalWeight += adj[i][parent[i]];
    }
    cout << "Total weight: " << totalWeight << "\n";

    return 0;
}
