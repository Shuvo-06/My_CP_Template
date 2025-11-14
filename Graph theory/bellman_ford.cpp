#include <bits/stdc++.h>
using namespace std;

/*
Bellman-Ford Shortest Path with Negative Cycle Detection

Purpose:
- Computes shortest distances from a single source to all nodes.
- Marks nodes affected by negative cycles as -1.
- Unreachable nodes have distance INF.
- neagting the weights would make it find positive cycles

Key Data:
- dis[v] = shortest distance from source to v (INF if unreachable)
- state[v] = -1 if v is part of or reachable through a negative cycle, 0 otherwise

Algorithm:
1. Initialize dis[src] = 0, others INF.
2. Relax all edges n-1 times: dis[v] = min(dis[v], dis[u] + w)
3. Detect negative cycles:
   - For edges that can still relax distances, mark affected nodes.
   - Propagate negative cycle influence via BFS/DFS.

Complexity:
- Time: O(n*m), Space: O(n + m)

Usage:
- Good for single-source shortest path in graphs with negative weights.
- Not for very large graphs if you need all-pairs distances.
- Common pitfalls: forgetting negative cycle propagation, integer overflow, unreachable nodes.
*/

#define int long long
struct Edge {
    int u, v, w;
};

const int inf = 4e18;

void bellmanFord(int n, int src, vector<Edge> &edges, vector<int> &dis, vector<int> &state) {
    dis.assign(n, inf);
    state.assign(n, 0);
    dis[src] = 0;

    // Standard Bellman–Ford relaxation: n-1 times
    for (int i = 0; i < n - 1; i++) {
        bool updated = false;
        for (auto &e : edges) {
            if (dis[e.u] == inf) continue;
            if (dis[e.u] + e.w < dis[e.v]) {
                dis[e.v] = dis[e.u] + e.w;
                updated = true;
            }
        }
        if (!updated) break;
    }

    // Detect vertices affected by negative cycles
    vector<int> visited(n, 0);
    queue<int> q;

    for (auto &e : edges) {
        if (dis[e.u] == inf) continue;
        if (dis[e.u] + e.w < dis[e.v] && !visited[e.v]) {
            visited[e.v] = 1;
            q.push(e.v);
        }
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        state[u] = -1; // mark as part of negative cycle
        for (auto &e : edges) {
            if (e.u == u && !visited[e.v]) {
                visited[e.v] = 1;
                q.push(e.v);
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef SUBLIME
        freopen("inputf.in", "r", stdin);
        freopen("outputf.out", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif

    while (true) {
        int n, m, k;
        cin >> n >> m >> k;
        if (n == 0 && m == 0 && k == 0) break;

        vector <Edge> v(m);
        for (auto &x : v) cin >> x.u >> x.v >> x.w;
        
        vector <vector <int>> dis(n, vector <int> (n)), state(n, vector <int> (n));

        for (int i = 0; i < n; i++) bellmanFord(n, i, v, dis[i], state[i]);

        while (k--) {
            int st, en;
            cin >> st >> en;

            if (state[st][en] != 0) cout << "-Infinity\n";
            else if (dis[st][en] == inf) cout << "Impossible\n";
            else cout << dis[st][en] << "\n";
        }
        cout << "\n";
    }
    return 0;
}
