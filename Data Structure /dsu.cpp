#include <bits/stdc++.h>
using namespace std;

/*
    Disjoint Set Union (DSU) or Union-Find Data Structure

    Features:
    - Path compression (in `find`) for nearly constant time queries.
    - Union by size (in `union_sets`) to keep tree height small.
    - Tracks parent nodes for reconstruction if needed.

    Time Complexities:
    - find(v): O(α(n)), almost constant.
    - union_sets(a, b), can_union_bipartite(u, v), union_bipartite(u, v) : O(α(n)), almost constant.
    - get_parent(v): O(1), returns direct parent.
*/


class DSU {
    vector<int> next;
public:
    vector<int> root, size, parent, color, depth;
    int n;
    bool is_bipartite = true;
    int num_components;

    DSU(int _n) : n(_n), num_components(_n) {
        root.resize(n + 1);
        size.resize(n + 1);
        parent.resize(n + 1);
        color.resize(n + 1);
        next.resize(n + 1);
        depth.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            root[i] = i;
            size[i] = 1;
            parent[i] = -1;
            color[i] = 0;
            next[i] = i + 1;
        }
        next[n] = n;
    }

    int find(int v) {
        if (root[v] == v) return v;
        int par = find(root[v]);
        depth[v] += depth[root[v]];
        return root[v] = par;
    }

    void union_sets(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            root[b] = a;
            size[a] += size[b];
            parent[b] = a;
            depth[b] = 1;
            num_components--;
        }
    }

    void union_bipartite(int a, int b) {
        int ra = find(a);
        int rb = find(b);
        if (ra == rb) {
            if ((color[a] ^ color[b]) != 1) is_bipartite = false;
            return;
        }

        if (size[ra] < size[rb]) {
            swap(ra, rb);
            swap(a, b);
        }

        root[rb] = ra;
        color[rb] = color[a] ^ color[b] ^ 1;
        size[ra] += size[rb];
        parent[rb] = ra;
        depth[rb] = 1;
        num_components--;
    }

    bool can_union_bipartite(int u, int v) {
        int ru = find(u);
        int rv = find(v);
        if (ru != rv) return true;
        return (color[u] ^ color[v]) == 1;
    }

    void unite_range(int x, int y) {
        int i = x;
        while (i < y) {
            int j = next[i];
            if (j > y) break;
            union_sets(i, j);
            next[i] = next[j];
            i = j;
        }
    }

    int get_depth(int x) {
        find(x);
        return depth[x];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    DSU dsu(5);
    dsu.union_sets(1, 2);
    dsu.union_sets(2, 4);
    dsu.union_sets(5, 3);

    /*
        Final DSU structure:

        Component 1:  1
                     / \
                    2   4

        Component 2: 3
                     \
                      5

        Representative (leader) of:
        - 1, 2, 4 → 1
        - 3, 5 → 3
    */

    return 0;
}
