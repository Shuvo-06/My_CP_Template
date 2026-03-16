#include <bits/stdc++.h>
using namespace std;

// for strings
// worst case time complexity : O(n * m)
// average case time complexity : O(n log n)
int longestCommonSubsequence(string &text1, string &text2) {
    vector <vector <int>> idx(26);
    for (int i = text1.size() - 1; i >= 0; i--) idx[text1[i] - 'a'].push_back(i);
        
    vector <int> lis;
    for (auto &x : text2) {
        for (auto y : idx[x - 'a']) {
            if (lis.empty() || lis.back() < y) lis.push_back(y);
            else lis[lower_bound(lis.begin(), lis.end(), y) - lis.begin()] = y;
        }
    }

    return lis.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    #ifdef SUBLIME
        freopen("inputf.in", "r", stdin);
        freopen("outputf.out", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector <int> v1(n), v2(n), hash(n + 1), idx, lis;
        for (auto &x : v1) cin >> x;
        for (auto &x : v2) cin >> x;

        for (int i = 0; i < n; i++) {
            hash[v1[i]] = i;
        }

        for (int i = 0; i < n; i++) idx.push_back(hash[v2[i]]);

        for (auto &x : idx) {
            if (lis.empty() || lis.back() < x) lis.push_back(x);
            else lis[lower_bound(lis.begin(), lis.end(), x) - lis.begin()] = x;
        }

        cout << 2 * (n - lis.size()) << "\n";
    }
    return 0;
}
