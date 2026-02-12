#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " -> " << x << endl;
// #define int long long
#define inf 100000000

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    #ifdef SUBLIME
        freopen("inputf.in", "r", stdin);
        freopen("outputf.out", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif
        
    int n, m;
    cin >> n >> m;
    vector <vector <int>> graph(n);
    vector <int> indeg(n), dp(n, -inf), par(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        indeg[v]++;
    }

    queue <int> q;
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto v : graph[u]) {
            if (dp[u] != -inf && dp[u] + 1 > dp[v]) {
                dp[v] = dp[u] + 1;
                par[v] = u;
            }

            indeg[v]--;
            if (indeg[v] == 0) {
                q.push(v);
            }
        }

    }

    if (dp[n - 1] == -inf) cout << "IMPOSSIBLE\n";
    else {
        vector <int> ans;
        int curr = n - 1;
        ans.push_back(curr);
        while (true) {
            curr = par[curr];
            ans.push_back(curr);
            if (curr == 0) break;
        }
        reverse(ans.begin(), ans.end());

        cout << dp[n - 1] << "\n";
        for (auto x : ans) cout << x + 1 << " ";
    }
    return 0;
}
