#include <bits/stdc++.h>
using namespace std;

const int n = 1e5;
vector<int> __root(n + 1), __size(n + 1), __parent(n + 1);

// Time complexity : O(1)
// makes a element in universal set
void make_set(int v) {
    __root[v] = v;
    __size[v] = 1;
    __parent[v] = -1;
}

// Time complecxity : O(α(N)) ~ O(4) at n = 1e600
// finds the root of a set
int root_set(int v) {
    if (__root[v] == v) return v;
    return __root[v] = root_set(__root[v]);
}

// Time complexity : O(1)
// finds the immediate parent of a node, returns -1 if it's root
int parent_node(int v) {
    return __parent[v];
}

// Time Complexity: O(α(n))
// joins two set a and b
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
    
    #ifndef ONLINE_JUDGE 
        freopen("inputf.in", "r", stdin);
        freopen("outputf.out", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif
    
    make_set(1); make_set(2); make_set(3); make_set(4); make_set(5);
    union_sets(1, 2);
    union_sets(1, 3);
    union_sets(4, 5);

    /*
         1     4
        / \     \
       2   3     5
        
    */
    return 0;
}
