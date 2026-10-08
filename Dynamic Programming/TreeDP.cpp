#include <bits/stdc++.h>
using namespace std;

const int N=2e5+5, L=20;
vector<int> adj[N],g[N],dep(N),tin(N),tout(N),par[N];
int timer;

void dfs(int u,int p) {
    tin[u]=++timer;
    par[u][0]=p;
    for(int j=1;j<L;j++) par[u][j]=par[par[u][j-1]][j-1];

    for(int v:adj[u]) if(v!=p) {
        dep[v]=dep[u]+1;
        dfs(v,u);
    }
    tout[u]=timer;
}

bool anc(int u,int v) {
    return tin[u]<=tin[v] && tout[v]<=tout[u];
}

int lca(int u,int v) {
    if(anc(u,v)) return u;
    if(anc(v,u)) return v;
    for(int j=L-1;j>=0;j--)
        if(!anc(par[u][j],v)) u=par[u][j];
    return par[u][0];
}

void add(int u,int v) {
    g[u].push_back(v);
    g[v].push_back(u);
}

vector<int> compress(vector<int> v) {
    sort(v.begin(),v.end(),[](int a,int b){return tin[a]<tin[b];});

    int m=v.size();
    for(int i=1;i<m;i++) v.push_back(lca(v[i-1],v[i]));

    sort(v.begin(),v.end(),[](int a,int b){return tin[a]<tin[b];});
    v.erase(unique(v.begin(),v.end()),v.end());

    vector<int> st;
    for(int u:v) {
        while(!st.empty() && !anc(st.back(),u)) st.pop_back();
        if(!st.empty()) add(st.back(),u);
        st.push_back(u);
    }
    return v;
}

long long dp[N][2];

void treeDP(int u,int p) {
    dp[u][0]=dp[u][1]=0;

    for(int v:g[u]) if(v!=p) {
        treeDP(v,u);

        // Example: maximum independent set
        dp[u][0]+=max(dp[v][0],dp[v][1]);
        dp[u][1]+=dp[v][0];
    }

    dp[u][1]++;
}
