#include <bits/stdc++.h>
using namespace std;

/*
All-Pairs Shortest Path (Floyd-Warshall) with Negative Cycle Detection

Key Data:
- dis[i][j] = shortest distance from i to j (inf if unreachable)
- state[i][j] = -1 if path passes through a negative cycle, 0 otherwise

Algorithm:
1. Initialize dis[i][i] = 0, set edges.
2. Floyd-Warshall: dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j])
3. Propagate negative cycles: if dis[k][k] < 0, mark all reachable paths through k as -Infinity.
4. Answer queries using dis and state.

Complexity:
- Time: O(n^3), Space: O(n^2)

Usage:
- Suitable for small/dense graphs (n <= 500) where all-pairs distances are needed.
- Avoid for very large or sparse graphs; use Bellman-Ford per source or Johnson’s algorithm instead.

Common Pitfalls:
- Forgetting negative cycle propagation
- Ignoring self-loops (dis[i][i] < 0)
- Multiple edges: always take min weight
- Checking for inf before printing
- Integer overflow: use long long
*/


#define int long long
const int inf = 4e18;

void floyd_warshall(int n, vector<vector<int>> &dis) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < n; j++) {
                if (dis[i][k] != inf && dis[k][j] != inf) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
    }
}

void neg_in_floyd_warshall(int n, vector <vector <int>> &dis, vector <vector <int>> &state) {
    for (int k = 0; k < n; k++) {
        if (dis[k][k] >= 0) continue; // k is not in a negative cycle
        for (int i = 0; i < n; i++) {
            if (dis[i][k] == inf) continue;
            for (int j = 0; j < n; j++) {
                if (dis[k][j] == inf) continue;
                state[i][j] = -1; // path from i to j goes through a negative cycle
            }
        }
    }
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef SUBLIME
        freopen("inputf.in", "r", stdin);
        freopen("outputf.out", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif

    while (true) {
        int n, m, k;
        cin >> n >> m >> k;
        if (n == 0 && m == 0 && k == 0) break;

        vector<vector<int>> dis(n, vector<int>(n, inf));
        vector<vector<int>> state(n, vector<int>(n, 0)); // -1 for negative cycle

        for (int i = 0; i < n; i++) dis[i][i] = 0;

        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            dis[u][v] = min(dis[u][v], (int)w);
        }

        floyd_warshall(n, dis);
        neg_in_floyd_warshall(n, dis, state);
        
        while (k--) {
            int u, v;
            cin >> u >> v;
            if (state[u][v] == -1) cout << "-Infinity\n";
            else if (dis[u][v] == inf) cout << "Impossible\n";
            else cout << dis[u][v] << "\n";
        }
        cout << "\n";
    }

    return 0;
}

// checked on https://open.kattis.com/problems/allpairspath
