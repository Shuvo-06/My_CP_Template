#include <bits/stdc++.h>
using namespace std;

void KMP(string &s, vector<int> &lps) {
    int n = s.size();
    lps.assign(n, 0);

    for (int i = 1; i < n; i++) {
        int j = lps[i - 1];

        while (j > 0 && s[i] != s[j])
            j = lps[j - 1];

        if (s[i] == s[j]) j++;

        lps[i] = j;
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

    int sz;
    string s, t;
    while (cin >> sz >> s >> t) {
        vector <int> lps;
        string ks = s + " " + t; // needs a separator
        KMP(ks, lps);

        for (auto i = s.size(); i < ks.size(); i++) {
            if (lps[i] >= sz) {
                cout << i - 2 * sz << "\n";
            }
        }

        cout << endl;
    }
    return 0;
}
