#include <bits/stdc++.h>
using namespace std;

vector <int> parent, vis, cycle, ans, e_id;
bool dfs(int u, int eid, vector <vector <pair <int, int>>> &graph) {
    if (!cycle.empty()) return true;
    vis[u] = 1;
    for (auto [v, id] : graph[u]) {
        if (v == parent[u] && eid == id) continue; // if not transitive
        if (vis[v] == 1) {
            cycle.push_back(v);
            ans.push_back(id);
            for (int x = u; x != v; x = parent[x]) {
                cycle.push_back(x);
                ans.push_back(e_id[x]);
            }
            // ans.push_back(ans.front()); // uncomment if you need explicit cycle notation
            // reverse(cycle.begin(), cycle.end()); // uncomment if direceted edges
            // reverse(ans.begin(), ans.end()); // uncomment if direceted edges
            return true;
        }
        if (vis[v] == 0) {
            parent[v] = u;
            e_id[v] = id;
            if (dfs(v, id, graph)) return true;
        }
    }

    vis[u] = 2;
    return false;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef SUBLIME
        freopen("inputf.in", "r", stdin);
        freopen("outputf.out", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif

    int n, m;
    cin >> n >> m;
    vector <vector <pair <int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // u++; v++; // uncomment if you 0-indxed is given
        graph[u].push_back({v, i});
        graph[v].push_back({u, i}); // uncomment if undirected edge
    }

    parent.resize(n + 1);
    vis.resize(n + 1);
    e_id.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;

        if (dfs(i, -1, graph)) {
            cout << ans.size() << "\n";
            for (auto x : cycle) cout << x << " ";
            cout << "\n";
            for (auto x : ans) cout << x << " ";
            cout << "\n";
            return 0;
        }
    }

    cout << -1 << "\n";
    return 0;
}
