#include <bits/stdc++.h>
using namespace std;

// Precomputation : O(logN)
// Query : O(1)

class LCA {
public:
    int n, LOG;
    vector<int> first, euler, depth;
    vector<vector<int>> st; // sparse table for RMQ

    LCA(int n) : n(n) {}

    void dfs(int u, int p, int d, const vector<vector<int>>& adj) {
        depth[u] = d;
        first[u] = euler.size();
        euler.push_back(u);

        for (int v : adj[u]) {
            if (v == p) continue;
            dfs(v, u, d + 1, adj);
            euler.push_back(u);
        }
    }

    void build(int root, const vector<vector<int>>& adj) {
        first.assign(n + 1, -1);
        depth.assign(n + 1, 0);
        euler.clear();
        euler.reserve(2 * n);
        dfs(root, -1, 0, adj);

        int m = euler.size();
        LOG = 32 - __builtin_clz(m);
        st.assign(m, vector<int>(LOG));

        // Build Sparse Table (RMQ on depth)
        for (int i = 0; i < m; i++) st[i][0] = euler[i];
        for (int j = 1; (1 << j) <= m; j++) {
            for (int i = 0; i + (1 << j) <= m; i++) {
                int a = st[i][j - 1];
                int b = st[i + (1 << (j - 1))][j - 1];
                st[i][j] = (depth[a] < depth[b] ? a : b);
            }
        }
    }

    int lca(int u, int v) {
        int L = first[u];
        int R = first[v];
        if (L > R) swap(L, R);
        int len = R - L + 1;
        int k = 31 - __builtin_clz(len);
        int a = st[L][k];
        int b = st[R - (1 << k) + 1][k];
        return (depth[a] < depth[b] ? a : b);
    }

    int dist(int u, int v) {
        int c = lca(u, v);
        return depth[u] + depth[v] - 2 * depth[c];
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
