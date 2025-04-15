#include <bits/stdc++.h>
using namespace std;
 
// dijkstra algorithm to find shortest path ditance from  single source to every other node
// can also be used to find shortest distnace from any node u to any node v
// Time complexity : O(VlogV + E)

void dijkstra(vector <vector <pair <int, long long int>>> &graph, vector <long long int> &dis) {
    priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>> pq;
    pq.push({0, 1});
    dis[1] = 0;

    while (!pq.empty()) {
        auto [time, node] = pq.top();
        pq.pop();
 
        if (time > dis[node]) continue;
 
        for (auto [x, w] : graph[node]) {
            if (dis[x] > time + w) {
                dis[x] = time + w;
                pq.push({dis[x], x});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
    int n, m;
    cin >> n >> m;
    vector <vector <pair <int, long long int>>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        long long int w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
 
    vector <long long int> dis(n + 1, LLONG_MAX);
    dijkstra(graph, dis);
 
    for (int i = 1; i <= n; i++) cout << (dis[i] == LLONG_MAX ? -1 : dis[i]) << " ";
    return 0;
}
