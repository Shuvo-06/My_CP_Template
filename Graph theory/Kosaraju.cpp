#include <bits/stdc++.h>
using namespace std;

// O(V + E), directed graph

vector<vector<int>> kosaraju(vector<vector<int>> &adj) {
    int n = adj.size();
    vector<vector<int>> rev(n), scc;
    vector<int> vis(n), order;

    for (int u = 0; u < n; u++)
        for (int v : adj[u]) rev[v].push_back(u);

    function<void(int)> dfs1 = [&](int u) {
        vis[u] = 1;
        for (int v : adj[u]) if (!vis[v]) dfs1(v);
        order.push_back(u);
    };

    function<void(int, vector<int>&)> dfs2 = [&](int u, vector<int> &cur) {
        vis[u] = 1;
        cur.push_back(u);
        for (int v : rev[u]) if (!vis[v]) dfs2(v, cur);
    };

    for (int i = 0; i < n; i++) if (!vis[i]) dfs1(i);
    fill(vis.begin(), vis.end(), 0);
    reverse(order.begin(), order.end());

    for (int u : order) if (!vis[u]) {
        vector<int> cur;
        dfs2(u, cur);
        scc.push_back(cur);
    }

    return scc;
}

vector<int> get_comp_no(vector<vector<int>> &scc, int n) {
    vector<int> comp_no(n);
    for (int i = 0; i < (int)scc.size(); i++)
        for (int u : scc[i]) comp_no[u] = i;
    return comp_no;
}

vector<vector<int>> get_condensation_graph(vector<vector<int>> &adj, vector<int> &comp_no) {
    int n = adj.size(), k = *max_element(comp_no.begin(), comp_no.end()) + 1;
    vector<vector<int>> dag(k);

    for (int u = 0; u < n; u++)
        for (int v : adj[u])
            if (comp_no[u] != comp_no[v])
                dag[comp_no[u]].push_back(comp_no[v]);

    for (auto &e : dag) {
        sort(e.begin(), e.end());
        e.erase(unique(e.begin(), e.end()), e.end());
    }

    return dag;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    #ifdef SUBLIME
        freopen("inputf.in", "r", stdin);
        freopen("outputf.out", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    auto scc = kosaraju(graph);
    auto comp_no = get_comp_no(scc, n);
    auto dag = get_condensation_graph(graph, comp_no);

    cout << scc.size() << "\n";
    for (auto &c : scc) {
        cout << c.size() << " ";
        for (int u : c) cout << u << " ";
        cout << "\n";
    }

    cout << "\nComponent numbers:\n";
    for (int u = 0; u < n; u++)
        cout << u << " -> " << comp_no[u] << "\n";

    cout << "\nCondensation DAG:\n";
    for (int u = 0; u < (int)dag.size(); u++) {
        cout << u << ": ";
        for (int v : dag[u]) cout << v << " ";
        cout << "\n";
    }

    return 0;
}
