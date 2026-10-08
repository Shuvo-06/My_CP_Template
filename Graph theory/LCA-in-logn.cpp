#include <bits/stdc++.h>
using namespace std;

class LCA {
public:
    int n, LOG;
    vector<int> depth;
    vector<vector<int>> up;
    vector<vector<int>> mn, mx; 
    vector<long long> dist_root;

    LCA(int n) : n(n) {
        LOG = 0;
        while ((1 << LOG) <= n) LOG++;

        depth.assign(n + 1, 0);
        up.assign(n + 1, vector<int>(LOG, -1));
        // mn.assign(n + 1, vector<int>(LOG, INT_MAX));
        // mx.assign(n + 1, vector<int>(LOG, INT_MIN));
        // dist_root.assign(n + 1, 0);
    }

    void dfs(int u, int p, vector <vector <int>> &adj) {
        up[u][0] = p;
        for (int i = 1; i < LOG; i++) {
            if (up[u][i - 1] != -1) up[u][i] = up[up[u][i-1] ][i-1];
            else break;
        }

        for (auto v : adj[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u, adj);
        }
    }

    void build(int root, vector <vector <int>> &adj) {
        dfs(root, -1, adj);
    }

    void dfs(int u, int p, vector<vector<pair<int,int>>>& adj) {
        up[u][0] = p;

        for (int i = 1; i < LOG; i++) {
            if (up[u][i-1] != -1) {
                up[u][i] = up[up[u][i-1]][i-1];
                mn[u][i] = min(mn[u][i-1], mn[ up[u][i-1] ][i-1]);
                mx[u][i] = max(mx[u][i-1], mx[ up[u][i-1] ][i-1]);
            }
            else break;
        }

        for (auto &[v, w] : adj[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dist_root[v] = dist_root[u] + w;

            mn[v][0] = w;
            mx[v][0] = w;

            dfs(v, u, adj);
        }
    }

    void build(int root, vector<vector<pair<int,int>>>& adj) {
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

    int kth(int u, int v, int k) {
        int lc = lca(u, v);
        int dis1 = depth[u] - depth[lc], dis2 = depth[v] - depth[lc];

        if (k > dis1 + dis2) return -1;
        else if (k < dis1) return lift(u, k);
        else if (k == dis1) return lc;
        else return lift(v, dis1 + dis2 - k);
    }

    pair <int, int> query(int u, int v) {
        int lc = lca(u, v);
        int dis1 = depth[u] - depth[lc];
        int dis2 = depth[v] - depth[lc];
 
        pair <int, int> ans = {INT_MAX, INT_MIN};
        for (int i = 0; i < LOG; i++) {
            if ((dis1 >> i) & 1) {
                ans = {min(ans.first, mn[u][i]), max(ans.second, mx[u][i])};
                u = up[u][i];
            }

            if ((dis2 >> i) & 1) {
                ans = {min(ans.first, mn[v][i]), max(ans.second, mx[v][i])};
                v = up[v][i];
            }
        }
        return ans;
    }

    int dist(int u, int v) {
        int lc = lca(u, v);
        return depth[u] + depth[v] - 2 * depth[lc];
    }

    long long disw(int u, int v) {
        int lc = lca(u, v);
        return dist_root[u] + dist_root[v] - 2 * dist_root[lc];
    }

    void add_leaf(int x, int p) {
        up[x][0] = p;
        depth[x] = depth[p] + 1;
        for (int i = 1; i < LOG; i++) {
            if (up[x][i - 1] != -1) up[x][i] = up[up[x][i - 1]][i - 1];
            else break;
        }
    }

    void remove_leaf(int x) {
        depth[x] = 0;
        up[x].assign(LOG, -1);
    }

    bool on_path(int u, int v, int x) {
        return dist(u, v) == dist(u, x) + dist(v, x);
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
    
    int tt;
    cin >> tt;
    while (tt--) {
        int n, root = 0;
        cin >> n;
        vector <vector <int>> graph(N);
        LCA tree(N);
        for (int i = 0; i < n; i++) {
            int u, v;
            cin >> u >> v;
            if (v == 0) root = u;
            else {
                graph[v].push_back(u);
                graph[u].push_back(v);
            }
        }

        tree.build(root, graph);

        int q;
        cin >> q;
        while (q--) {
            int op;
            cin >> op;
            if (op == 0) {
                int p, x;
                cin >> p >> x;
                tree.add_leaf(x, p);
            }
            else if (op == 1) {
                int x;
                cin >> x;
                tree.remove_leaf(x);
            }
            else {
                int x, k;
                cin >> x >> k;
                cout << tree.lift(x, k) << "\n";
            }
        }
    }
    return 0;
}
