#include <bits/stdc++.h>
using namespace std;

// only applicable acyclic hierarchial structures
// Precompuatation : O(logN)
// Query : O(logN)

class LCA {
public : 
    int n, LOG;
    vector<int> depth;
    vector<vector<int>> up;

    LCA(int n) : n(n) {
        LOG = 0;
        while ((1 << LOG) <= n) LOG++;
        up.assign(n + 1, vector<int>(LOG, -1));
        depth.assign(n + 1, 0);
    }

    void dfs(int u, int p, vector<vector<int>>& adj) {
        up[u][0] = p;
        for (int i = 1; i < LOG; i++) {
            if (up[u][i - 1] != -1) up[u][i] = up[up[u][i - 1]][i - 1];
        }

        for (auto v : adj[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u, adj);
        }
    }

    void build(int root, const vector<vector<int>>& adj) {
        dfs(root, -1, adj);
    }

    int lift(int u, int k) {
        for (int i = 0; i < LOG; i++) {
            if (k & (1 << i)) {
                u = up[u][i];
                if (u == -1) break;
            }
        }
        return u;
    }

    int lca(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);
        a = lift(a, depth[a] - depth[b]);
        if (a == b) return a;

        for (int i = LOG - 1; i >= 0; i--) {
            if (up[a][i] != up[b][i]) {
                a = up[a][i];
                b = up[b][i];
            }
        }
        return up[a][0];
    }

    int dist(int a, int b) {
        int c = lca(a, b);
        return depth[a] + depth[b] - 2 * depth[c];
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef SUBLIME
        freopen("inputf.in", "r", stdin);
        freopen("outputf.out", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif

    int n, q;
    cin >> n >> q;
    vector <vector <int>> vp(n);
    for (int i = 1; i < n; i++) {
        int j;
        cin >> j;
        vp[i].push_back(j);
        vp[j].push_back(i);
    }

    LCA t(n);
    t.build(0, vp);
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << t.lca(u, v) << "\n";
    }
    return 0;
}
