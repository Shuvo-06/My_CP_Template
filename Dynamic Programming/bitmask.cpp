#include <bits/stdc++.h>
using namespace std;

int n;
long long a[20][20], dp[1<<20];

long long dfs(int mask) {
    int i=__builtin_popcount(mask);
    if(i==n) return 0;

    long long &res=dp[mask];
    if(res!=-1) return res;

    res=LLONG_MIN;
    for(int j=0;j<n;j++)
        if(!(mask>>j&1))
            res=max(res,a[i][j]+dfs(mask|1<<j));

    return res;
}

int main() {
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];

    memset(dp,-1,sizeof(dp));
    cout<<dfs(0)<<'\n';
}
