#include <bits/stdc++.h>
using namespace std;

// Time complexity : O(V + E)
// must be directed graph

vector<vector<int>> kosaraju(vector<vector<int>> &adj) {
    int n = adj.size();
    vector<vector<int>> rev(n), scc;
    vector<int> vis(n), order;

    for (int u = 0; u < n; u++) for (int v : adj[u]) rev[v].push_back(u);

    function <void(int)> dfs1 = [&](int u) {
        vis[u] = 1;
        for (int v : adj[u]) {
            if (!vis[v]) dfs1(v);
        }
        order.push_back(u);
    };

    function <void(int, vector<int>&)> dfs2 = [&](int u, vector<int> &cur) {
        vis[u] = 1;
        cur.push_back(u);

        for (int v : rev[u]) {
            if (!vis[v]) dfs2(v, cur);
        }
    };

    for (int i = 0; i < n; i++) {
        if (!vis[i]) dfs1(i);
    }

    fill(vis.begin(), vis.end(), 0);
    reverse(order.begin(), order.end());

    for (int u : order) {
        if (vis[u]) continue;

        vector<int> cur;
        dfs2(u, cur);
        scc.push_back(cur);
    }

    return scc;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    #ifdef SUBLIME
        freopen("inputf.in", "r", stdin);
        freopen("outputf.out", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif

    int n, m;
    cin >> n >> m;
    vector <vector <int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    auto comp = kosaraju(graph);

    cout << comp.size() << "\n";
    for (auto x : comp) {
        cout << x.size() << " ";
        for (auto y : x) cout << y << " ";
        cout << "\n";
    }

    return 0;
}
