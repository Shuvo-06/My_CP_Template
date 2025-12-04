#include <bits/stdc++.h>
using namespace std;

// static_ett_with_lazy_seg.cpp
// ChatGPT version, might be wrong
// Static Euler Tour Tree (ETT) + Lazy Segment Tree (range add, range sum)
// - Build from adjacency list and an initial node value array
// - Supports: point update/query, subtree range update/query
// - Complexity: O(n log n) build, O(log n) per query/update

struct LazySeg {
    int n;
    vector<long long> st;    // segment sums
    vector<long long> lz;    // lazy add

    LazySeg() { n = 0; }
    LazySeg(int _n) { init(_n); }

    void init(int _n) {
        n = 1; while (n < _n) n <<= 1;
        st.assign(2 * n, 0);
        lz.assign(2 * n, 0);
    }

    void build_from(const vector<long long>& a) {
        int m = (int)a.size();
        init(m);
        for (int i = 0; i < m; ++i) st[n + i] = a[i];
        for (int i = n - 1; i >= 1; --i) st[i] = st[2*i] + st[2*i+1];
    }

    void apply(int idx, int len, long long val) {
        st[idx] += val * len;
        lz[idx] += val;
    }

    void push(int idx, int l, int r) {
        if (lz[idx] != 0 && idx < n) {
            int mid = (l + r) >> 1;
            apply(idx<<1, mid - l + 1, lz[idx]);
            apply(idx<<1|1, r - mid, lz[idx]);
            lz[idx] = 0;
        }
    }

    // internal update on [ql, qr]
    void upd(int idx, int l, int r, int ql, int qr, long long val) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            apply(idx, r - l + 1, val);
            return;
        }
        push(idx, l, r);
        int mid = (l + r) >> 1;
        upd(idx<<1, l, mid, ql, qr, val);
        upd(idx<<1|1, mid+1, r, ql, qr, val);
        st[idx] = st[idx<<1] + st[idx<<1|1];
    }

    long long query(int idx, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return st[idx];
        push(idx, l, r);
        int mid = (l + r) >> 1;
        return query(idx<<1, l, mid, ql, qr) + query(idx<<1|1, mid+1, r, ql, qr);
    }

    // public wrappers (0-based indices)
    void range_add(int l, int r, long long val) {
        if (l > r) return;
        upd(1, 0, n-1, l, r, val);
    }

    long long range_sum(int l, int r) {
        if (l > r) return 0;
        return query(1, 0, n-1, l, r);
    }

    // point set (assign): get current value then add delta
    void point_set(int pos, long long new_val) {
        long long cur = range_sum(pos, pos);
        long long delta = new_val - cur;
        range_add(pos, pos, delta);
    }

    long long point_get(int pos) {
        return range_sum(pos, pos);
    }
};

struct StaticETT {
    int n;
    vector<vector<int>> adj;
    vector<int> parent, depth, tin, tout, tour; // tour stores nodes in order of entry
    int timer;
    LazySeg seg;

    StaticETT() : n(0), timer(0) {}
    StaticETT(int _n) { init(_n); }

    void init(int _n) {
        n = _n;
        adj.assign(n, {});
        parent.assign(n, -1);
        depth.assign(n, 0);
        tin.assign(n, -1);
        tout.assign(n, -1);
        tour.clear();
        timer = 0;
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // dfs to compute tin/tout and euler order (entry only)
    void dfs(int u, int p) {
        parent[u] = p;
        tin[u] = timer++;
        tour.push_back(u);
        for (int v : adj[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
        tout[u] = timer - 1; // inclusive interval [tin[u], tout[u]] contains subtree
    }

    // build from adjacency + initial values array (0-based node values)
    void build(int root, const vector<long long>& values) {
        tour.clear();
        timer = 0;
        dfs(root, -1);
        // map values to euler order
        vector<long long> arr(n, 0);
        for (int i = 0; i < n; ++i) {
            arr[tin[i]] = values[i];
        }
        seg.build_from(arr);
    }

    // subtree range add: add 'val' to every node in subtree of u
    void subtree_add(int u, long long val) {
        seg.range_add(tin[u], tout[u], val);
    }

    // subtree query (sum of values in subtree)
    long long subtree_sum(int u) {
        return seg.range_sum(tin[u], tout[u]);
    }

    // point operations
    void point_set(int u, long long val) {
        seg.point_set(tin[u], val);
    }
    long long point_get(int u) {
        return seg.point_get(tin[u]);
    }

    // LCA via binary lifting (optional helper) - useful if you want to implement path queries
    vector<vector<int>> up; // up[k][v] is 2^k-th ancestor
    void build_lca() {
        int LOG = 1;
        while ((1<<LOG) <= n) LOG++;
        up.assign(LOG, vector<int>(n, -1));
        for (int v = 0; v < n; ++v) up[0][v] = parent[v] < 0 ? v : parent[v];
        for (int k = 1; k < LOG; ++k) {
            for (int v = 0; v < n; ++v) up[k][v] = up[k-1][ up[k-1][v] ];
        }
    }

    int lca(int a, int b) {
        if (a == b) return a;
        if (depth[a] < depth[b]) swap(a,b);
        int diff = depth[a] - depth[b];
        for (int k = 0; diff; ++k) {
            if (diff & 1) a = up[k][a];
            diff >>= 1;
        }
        if (a == b) return a;
        for (int k = (int)up.size()-1; k >= 0; --k) {
            if (up[k][a] != up[k][b]) {
                a = up[k][a]; b = up[k][b];
            }
        }
        return parent[a];
    }

    // NOTE: path queries/updates are NOT contiguous in ETT flattened array in general
    // If you need efficient path operations, combine this class with HLD. We provide a naive O(length of path * log n)
    // helper that climbs from a to b applying point updates/queries along the path. This is fine for small paths.

    // naive path add (walks and updates each node individually): O(path length * log n)
    void path_add_naive(int a, int b, long long val) {
        int c = lca(a,b);
        // climb a -> c
        int u = a;
        while (u != c) {
            seg.range_add(tin[u], tin[u], val);
            u = parent[u];
        }
        // climb b -> c (collect nodes to avoid double-updating c)
        vector<int> stack;
        u = b;
        while (u != c) {
            stack.push_back(u);
            u = parent[u];
        }
        for (int node : stack) seg.range_add(tin[node], tin[node], val);
        // add c once
        seg.range_add(tin[c], tin[c], val);
    }

    long long path_sum_naive(int a, int b) {
        int c = lca(a,b);
        long long ans = 0;
        int u = a;
        while (u != c) {
            ans += seg.range_sum(tin[u], tin[u]);
            u = parent[u];
        }
        vector<int> stack;
        u = b;
        while (u != c) {
            stack.push_back(u);
            u = parent[u];
        }
        for (int node : stack) ans += seg.range_sum(tin[node], tin[node]);
        ans += seg.range_sum(tin[c], tin[c]);
        return ans;
    }
};

// -------------------------------
// Example usage (not included in library):
// - Create StaticETT ett(n)
// - add_edge(u,v) for all edges
// - ett.build(root, values)
// - ett.subtree_add(u, delta)
// - ett.subtree_sum(u)
// - ett.point_set(u, val); ett.point_get(u)
// - Optional: ett.build_lca(); ett.path_add_naive(a,b,val); etc.
// -------------------------------

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // small demonstration
    int n = 7;
    StaticETT ett(n);
    ett.add_edge(0,1); ett.add_edge(0,2); ett.add_edge(1,3); ett.add_edge(1,4);
    ett.add_edge(2,5); ett.add_edge(2,6);
    vector<long long> vals = {1,2,3,4,5,6,7};
    ett.build(0, vals);
    // subtree of 1 contains nodes 1,3,4 -> values 2+4+5 = 11
    cout << "subtree_sum(1) = " << ett.subtree_sum(1) << "\n";
    ett.subtree_add(1, 10); // add 10 to each node in subtree(1)
    cout << "subtree_sum(1) after +10 per node = " << ett.subtree_sum(1) << "\n";

    return 0;
}
