#include <bits/stdc++.h>
using namespace std;

class DSU {
    public :
        vector <int> root, size;
        int n;

        DSU(int _n) : n(_n) {
            root.resize(n + 1);
            size.resize(n + 1);
            for (int i = 1; i <= n; ++i) {
                root[i] = i;
                size[i] = 1;
            }
        }

        int find(int v) {
            if (root[v] == v) return v;
            return root[v] = find(root[v]);
        }

        void union_sets(int a, int b) {
            a = find(a);
            b = find(b);
            if (a != b) {
                if (size[a] < size[b]) swap(a, b);
                root[b] = a;
                size[a] += size[b];
            }
        }
};

typedef struct {
    int u, v;
    long long int w;
} edge;



/*
A Minimum Spanning Tree (MST) of a connected, undirected graph is a subset of the edges that connects all the vertices together,
without any cycles, and with the minimum possible total edge weight.

Kruskal's Algorithm is a greedy algorithm used to find the MST of a connected, undirected, weighted graph.
It is ideal for sparse graphs where edges are fewer than n².

Time Complexity :  O(E log E)
*/

long long int kruskal(vector <edge> &v, DSU &dsu) {
    sort(v.begin(), v.end(), [](edge &a, edge &b) {
        return a.w < b.w;
    });
    
    long long int mst = 0;
    for (auto e : v) {
        if (dsu.find(e.u) != dsu.find(e.v)) {
            dsu.union_sets(e.u, e.v);
            mst += e.w;
        }
    }
    return mst;
}


int main() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    vector <edge> v(m);
    for (auto &x : v) cin >> x.u >> x.v >> x.w;
    
    long long int mst = kruskal(v, dsu);

    int cnt = 0;
    for (int i = 1; i <= n; i++) cnt += (dsu.root[i] == i);
    
    if (cnt == 1) cout << mst << "\n";
    else cout << "IMPOSSIBLE\n";
    return 0;
}
