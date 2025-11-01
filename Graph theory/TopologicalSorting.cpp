#include <bits/stdc++.h>
using namespace std;

bool topo_sort(int n, vector <pair <int, int>> &edges, vector <int> &ans) {
    vector <int> indeg(n + 1, 0);
    vector <vector <int>> graph(n + 1);
    for (auto [x, y] : edges) {
        indeg[y]++;
        graph[x].push_back(y);
    }
        
    queue <int> q;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        ans.push_back(u);
        q.pop();

        for (auto v : graph[u]) {
            indeg[v]--;
            if (indeg[v] == 0) q.push(v);
        }
    }

    return ((int)ans.size() == n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    int n, q;
    cin >> n >> q;
    vector <pair <int, int>> vp(q);
    for (auto &[x, y] : vp) cin >> x >> y;

    vector <int> v;
    if (!topo_sort(n, vp, v)) cout << "Sandro fails.\n";
    else {
        for (auto x : v) cout << x << " ";
    }
}
