#include <bits/stdc++.h>
using namespace std;

int counter = 1;
vector <int> group;
vector<bool> vis;

void dfs(vector<vector<int>> &graph, int node) {
  group[node] = counter;
  vis[node] = true;
  for (auto child : graph[node]) {
    if (!vis[child]) {
      dfs(graph, child);
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  int n, m;
  cin >> n >> m;
  vector <vector<int>> graph(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  
  group.resize(n + 1);
  vis.resize(n + 1, false);
  for (int i = 1; i <= n; i++) {
    if (!vis[i]){
      dfs(graph, i);
      counter++;
    }
  }
  
  for (int i = 1; i <= n; i++) {
    cout << i << " -> " << group[i] << "\n";
  }
  return 0;
}
