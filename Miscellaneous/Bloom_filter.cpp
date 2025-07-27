#include <bits/stdc++.h>
using namespace std;


// Probabilistic membership test
// Time complexity : O(nl + ql)
// probability of collision : O(1 / M2) 
// for triple, use {97, 1e9 + 21}

using ull = unsigned long long int;

ull hash(const string &s, ull p, ull mod) {
    ull h = 0;
    for (char c : s) h = (h * p + (c - 'a' + 1)) % MOD;
    return h;
}

int main() {
    int n, q;
    cin >> n;

    set<pair<ull, ull>> hashes;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        hashes.insert({hash(s, 31, 1e9 + 7), hash(s, 53, 1e9 + 9)});
    }

	cin >> q;
    while (q--) {
        string s;
        cin >> s;
        if (hashes.count({hash(s, 31, 1e9 + 7), hash(s, 53, 1e9 + 9)})) cout << "YES\n";
        else cout << "NO\n";
    }
}
