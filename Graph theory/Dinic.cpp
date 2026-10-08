#include <bits/stdc++.h>
using namespace std;

class Dinic {
    struct Edge {
        int to, cap, rev;
    };

    int n;
    vector<vector<Edge>> adj;
    vector<int> level, ptr;

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);

        queue<int> q;
        q.push(s);
        level[s] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto e : adj[u]) {
                if (e.cap > 0 && level[e.to] == -1) {
                    level[e.to] = level[u] + 1;
                    q.push(e.to);
                }
            }
        }

        return level[t] != -1;
    }

    int dfs(int u, int t, int flow) {
        if (u == t) return flow;

        for (int &i = ptr[u]; i < adj[u].size(); i++) {
            Edge &e = adj[u][i];

            if (e.cap > 0 && level[e.to] == level[u] + 1) {
                int f = dfs(e.to, t, min(flow, e.cap));

                if (f) {
                    e.cap -= f;
                    adj[e.to][e.rev].cap += f;
                    return f;
                }
            }
        }

        return 0;
    }

public:
    Dinic(int n) : n(n), adj(n), level(n), ptr(n) {}

    void addEdge(int u, int v, int cap) {
        Edge a = {v, cap, (int)adj[v].size()};
        Edge b = {u, 0, (int)adj[u].size()};

        adj[u].push_back(a);
        adj[v].push_back(b);
    }

    int maxflow(int s, int t) {
        int flow = 0;

        while (bfs(s, t)) {
            fill(ptr.begin(), ptr.end(), 0);

            while (int f = dfs(s, t, INT_MAX))
                flow += f;
        }

        return flow;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    Dinic dinic(n);

    while (m--) {
        int u, v, cap;
        cin >> u >> v >> cap;
        dinic.addEdge(u, v, cap);
    }

    int s, t;
    cin >> s >> t;

    cout << dinic.maxflow(s, t) << '\n';
}
