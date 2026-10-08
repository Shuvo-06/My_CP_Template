#include <bits/stdc++.h>
using namepsace std;

bool dfs(int u,vector<vector<int>>&adj, vector<int>&vis, vector<int>&par, vector<int>&cyc) {
    vis[u]=1;
    for(int v:adj[u]) {
        if(!vis[v]) {
            par[v]=u;
            if(dfs(v,adj,vis,par,cyc)) return true;
        }
        else if(vis[v]==1) {
            cyc.push_back(v);
            for(int x=u;x!=v;x=par[x]) cyc.push_back(x);
            cyc.push_back(v);
            return true;
        }
    }
    vis[u]=2;
    return false;
}

vector<int> findCycle(vector<vector<int>>&adj) {
    int n=adj.size();
    vector<int> vis(n),par(n,-1),cyc;
    for(int u=0;u<n;u++)
        if(!vis[u] && dfs(u,adj,vis,par,cyc))
            return cyc;

    return {};
}

int main() {}
