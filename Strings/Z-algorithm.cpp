#include <bits/stdc++.h>
using namespace std;

#define db(X) cerr << #X << " -> " << X << endl;
// link : https://atcoder.jp/contests/abc430/tasks/abc430_e

void Z(string &s, vector<int> &z) {
    int n = s.size();
    z.assign(n, 0);

    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
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
    
    int tt;
    cin >> tt;
    while (tt--) {
        string a, b;
        cin >> a >> b;

        string s = b + a + a;
        vector <int> z;
        Z(s, z);

        int ans = -1, n = a.size();
        for (int i = n; i < 2 * n; i++) {
            if (z[i] >= n) {
                ans = i - n;
                break;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
