#include <bits/stdc++.h>
using namespace std;

// declare_dsu -> O(n)
// make_set, parent_node -> O(1)
// root_set, union_sets -> O(logN) amortized

vector <int> __root, __size, __parent;
 
void make_set(int v) {
    __root[v] = v;
    __size[v] = 1;
    __parent[v] = -1;
}

void declare_dsu(int n) {
    __root.resize(n + 1);
    __size.resize(n + 1);
    __parent.resize(n + 1);
 
    for (int i = 1; i <= n; i++) make_set(i);
}

int root_set(int v) {
    if (__root[v] == v) return v;
    return __root[v] = root_set(__root[v]);
}

int parent_node(int v) {
    return __parent[v];
}

void union_sets(int a, int b) {
    a = root_set(a);
    b = root_set(b);
    if (a != b) {
        if (__size[a] < __size[b]) swap(a, b);
        __root[b] = a;
        __size[a] += __size[b];
        __parent[b] = a;
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    declare_dsu(5);
    union_sets(1, 2);
    union_sets(2, 4);
    union_sets(5, 3);

    /*
    
        1    3
       / \    \
      4   2    5

    */
    return 0;
}
