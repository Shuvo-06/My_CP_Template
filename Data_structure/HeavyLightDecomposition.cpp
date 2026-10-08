#include <bits/stdc++.h>
using namespace std;

class HLD {
    int n, timer;
    vector<vector<int>> adj;
    vector<int> par, dep, sz, heavy, head, pos, seg;

    int dfs(int u, int p) {
        par[u] = p;
        sz[u] = 1;
        int mx = 0;
        for (int v : adj[u]) {
            if (v == p) continue;
            dep[v] = dep[u] + 1;
            int s = dfs(v, u);
            sz[u] += s;
            if (s > mx) mx = s, heavy[u] = v;
        }

        return sz[u];
    }

    void decompose(int u, int h) {
        head[u] = h;
        pos[u] = timer++;
        if (heavy[u] != -1) decompose(heavy[u], h);
        for (int v : adj[u]) {
            if (v == par[u] || v == heavy[u]) continue;
            decompose(v, v);
        }
    }

    void update(int idx, int l, int r, int p, int x) {
        if (l == r) {
            seg[idx] = x;
            return;
        }
        int m = (l + r) / 2;
        if (p <= m) update(2 * idx + 1, l, m, p, x);
        else update(2 * idx + 2, m + 1, r, p, x);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    int query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return seg[idx];

        int m = (l + r) / 2;
        return query(2 * idx + 1, l, m, ql, qr) + query(2 * idx + 2, m + 1, r, ql, qr);
    }

public:
    HLD(int n) : n(n), timer(0), adj(n), par(n), dep(n), sz(n), heavy(n, -1), head(n), pos(n), seg(4 * n) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void build(int root = 0) {
        dfs(root, -1);
        decompose(root, root);
    }

    void update(int u, int x) {
        update(0, 0, n - 1, pos[u], x);
    }

    int query(int u, int v) {
        int ans = 0;
        while (head[u] != head[v]) {
            if (dep[head[u]] < dep[head[v]]) swap(u, v);
            ans += query(0, 0, n - 1, pos[head[u]], pos[u]);
            u = par[head[u]];
        }

        if (dep[u] > dep[v]) swap(u, v);
        ans += query(0, 0, n - 1, pos[u], pos[v]);
        return ans;
    }

    int subtree(int u) {
        return query(0, 0, n - 1, pos[u], pos[u] + sz[u] - 1);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    HLD hld(n);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        hld.addEdge(u, v);
    }

    hld.build();

    int q;
    cin >> q;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int u, x;
            cin >> u >> x;
            hld.update(u, x);
        }
        else if (type == 2) {
            int u, v;
            cin >> u >> v;
            cout << hld.query(u, v) << '\n';
        }
        else {
            int u;
            cin >> u;
            cout << hld.subtree(u) << '\n';
        }
    }
}
