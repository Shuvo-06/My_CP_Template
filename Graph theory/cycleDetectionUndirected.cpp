#include <bits/stdc++.h>
using namespace std;

bool dfs(int u,int p,vector<vector<int>>&adj,vector<int>&vis,vector<int>&par,vector<int>&cyc) {
    vis[u]=1;
    for(int v:adj[u]) {
        if(v==p) continue;
        if(!vis[v]) {
            par[v]=u;
            if(dfs(v,u,adj,vis,par,cyc)) return true;
        }
        else {
            cyc.push_back(v);
            for(int x=u;x!=v;x=par[x]) cyc.push_back(x);
            cyc.push_back(v);
            return true;
        }
    }
    return false;
}

vector<int> findCycle(vector<vector<int>>&adj) {
    int n=adj.size();
    vector<int> vis(n),par(n,-1),cyc;

    for(int u=0;u<n;u++)
        if(!vis[u] && dfs(u,-1,adj,vis,par,cyc))
            return cyc;

    return {};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}
