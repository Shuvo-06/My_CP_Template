#include <bits/stdc++.h>
using namespace std;

vector <vector<int>> graph;
vector <bool> vis;
void dfs(int vertex){
  vis[vertex] = true;
  for (auto child : graph[vertex]) {
    if (!vis[child]) dfs(child);
  }
  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  // Time complexity : O(V + E)
  // Most frequent algorithm to traverse in a graph
  
	int node, edge;
	cin >> node >> edge;
	graph.resize(node + 1);
	vis.resize(node + 1, false);
	for (int _ = 0; _ < edge; _++){
	  int u, v;
	  cin >> u >> v;
	  graph[u].push_back(v);
	  graph[v].push_back(u);
	}
	
	dfs(1); // considering node-1 as root node
	return 0;
}
