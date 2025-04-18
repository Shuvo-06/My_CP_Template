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
    - union_sets(a, b): O(α(n)), almost constant.
    - get_parent(v): O(1), returns direct parent (not necessarily the root).
*/


class DSU {
    vector <int> root, size, parent;
    int n;

    public:
        DSU(int _n) : n(_n) {
            root.resize(n + 1);
            size.resize(n + 1);
            parent.resize(n + 1);
            for (int i = 1; i <= n; ++i) {
                root[i] = i;
                size[i] = 1;
                parent[i] = -1;
            }
        }

        int find(int v) {
            if (root[v] == v) return v;
            return root[v] = find(root[v]);
        }

        int get_parent(int v) {
            return parent[v];
        }

        void union_sets(int a, int b) {
            a = find(a);
            b = find(b);
            if (a != b) {
                if (size[a] < size[b]) swap(a, b);
                root[b] = a;
                size[a] += size[b];
                parent[b] = a;
            }
        }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

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
