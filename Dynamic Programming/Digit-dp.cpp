#include <bits/stdc++.h>
using namespace std;

string l, r;
long long int dp[19][2][2][2];
long long int mmul;
long long int count(int pos, bool tub, bool tlb, bool lzr) {
    if (pos == (int)l.size()) return !lzr;
    if (dp[pos][tub][tlb][lzr] != -1) return dp[pos][tub][tlb][lzr];

    long long int res = 0;
    int ub = (tub ? r[pos] - '0' : 9);
    int lb = (tlb ? l[pos] - '0' : 0);
    for (int i = lb; i <= ub; i++) {
        int mul = 1;
        bool new_lzr = lzr && (i == 0);
        if (!new_lzr) mul = i;

        res = max(res, mul * count(pos + 1, tub && (i == ub), tlb && (i == lb), new_lzr));
    }
    return dp[pos][tub][tlb][lzr] = res;
}

long long int backtrack(int pos, bool tub, bool tlb, bool lzr) {
    if (pos == (int)l.size()) return !lzr;

    long long int res = dp[pos][tub][tlb][lzr];
    int ub = (tub ? r[pos] - '0' : 9);
    int lb = (tlb ? l[pos] - '0' : 0);

    for (int i = lb; i <= ub; i++) {
        int mul = 1;
        bool new_lzr = lzr && (i == 0);
        if (!new_lzr) mul = i;

        if (res == mul * count(pos + 1, tub && (i == ub), tlb && (i == lb), new_lzr)) {
            if (!new_lzr) cout << i;
            backtrack(pos + 1, tub && (i == ub), tlb && (i == lb), new_lzr); 
            break;
        }
    }
    return res;;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    #ifdef SUBLIME
        freopen("inputf.in", "r", stdin);
        freopen("outputf.out", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif

    cin >> l >> r;
    reverse(l.begin(), l.end());
    while (l.size() != r.size()) l.push_back('0');
    reverse(l.begin(), l.end());

    memset(dp, -1, sizeof dp);
    mmul = count(0, true, true, true);
    backtrack(0, true, true, true);

    return 0;
}
