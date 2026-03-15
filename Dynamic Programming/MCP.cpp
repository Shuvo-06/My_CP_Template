#include <bits/stdc++.h>
using namespace std;

int n;
vector <pair <int, int>> v;
vector <vector <int>> dp;
int count(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    if (l == r) return dp[l][r] = 0;
    if (r - l == 1) dp[l][r] = v[l].first * v[l].second * v[r].second;

    int res = INT_MAX;
    for (int k = l; k <= r - 1; k++) {
        res = min(res, count(l, k) + count(k + 1, r) + v[l].first * v[k].second * v[r].second);
    }
    return dp[l][r] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    #ifdef SUBLIME
        freopen("inputf.in", "r", stdin);
        freopen("outputf.out", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif

    cin >> n;
    dp.resize(n, vector <int> (n, -1));
    v.resize(n);
    for (auto &[x, y] : v) cin >> x >> y;

    cout << count(0, n - 1) << "\n";

    return 0;
}
