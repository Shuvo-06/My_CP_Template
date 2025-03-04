#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector <vector <int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    queue <int> q;
    vector<bool> vis(n + 1, false);
    q.push(1);
    vis[1] = true;

    while (!q.empty()) {
        int source = q.front();
        q.pop();

        for (auto x : graph[source]) {
            if (vis[x]) continue;

            q.push(x);
            vis[x] = true;
        }
    }

    return 0;
}
