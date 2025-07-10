#include <bits/stdc++.h>
using namespace std;

/*
    Disjoint Set Union (DSU) or Union-Find Data Structure

    Features:
    - Path compression (in `find`) for nearly constant time queries.
    - Union by size (in `unite`) to keep tree height small.
    - Keep track of bipartite state

    Time Complexities:
    - find(v): O(α(n)), almost constant.
    - unite(a, b) : O(α(n)), almost constant.
    - unite_range(x, y) - O(n) in total
    - same color(x, y) same_set(x, y) is_bipartite_after(x, y) : O(α(n)), almost constant.
    - is_bipartite() : O(1)
*/

#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int u, v, ind;
    long long int w;
} edge;

class DSU {
    int n;
    bool is_bpt = true;
    vector <int> next;

public:
    vector<int> size, color, root, rank; // color[v] = parity of distance from root (0 = same, 1 = different)

    DSU(int _n) : n(_n) {
        size.resize(n + 1, 1);
        rank.resize(n + 1, 1);
        color.resize(n + 1, 0);

        root.resize(n + 1);
        next.resize(n + 1);
        iota(root.begin(), root.end(), 0);
        iota(next.begin(), next.end(), 0);
    }

    int find(int v) {
        if (v == root[v]) return v;
        int par = find(root[v]);
        color[v] ^= color[root[v]]; // color[v] = (color[v] + color[root[v]]) % 2
        root[v] = par;
        return root[v];
    }

    bool unite(int u, int v) {
        int ru = find(u);
        int rv = find(v);
        if (ru == rv) {
            if (color[u] == color[v]) is_bpt = false;
            return false;
        }

        if (size[ru] < size[rv]) {
            swap(u, v);
            swap(ru, rv);
        }

        root[rv] = ru;
        size[ru] += size[rv];
        color[rv] = color[u] ^ color[v] ^ 1; // color[rv] = (color[u] + color[v] + 1) % 2
        return true;
    }

    int find_next(int i) { return (i == next[i] ? i : next[i] = find_next(next[i])); }

    void unite_range(int l, int r) {
        int x = find_next(l);
        while (x < r) {
            unite(x, x + 1);
            next[x] = x + 1;
            x = find_next(x);
        }
    }

    bool same_color(int u, int v) { return (find(u) == find(v) && color[u] == color[v]); }
    bool same_set(int u, int v) { return find(u) == find(v); }
    bool is_bipartite() const { return is_bpt; }
    bool is_bipartite_after(int u, int v) { return (find(u) != find(v) || color[u] != color[v]);}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef SUBLIME
        freopen("inputf.in", "r", stdin);
        freopen("outputf.out", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif

    int n;
    cin >> n;
    DSU dsu(n);
    
    return 0;
}
