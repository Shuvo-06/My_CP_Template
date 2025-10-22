#include <bits/stdc++.h>
using namespace std;

// problem : Toph - not-my-fault 
#define int long long int

int f(int a, int m) {
    return (a * a + a) % m;
}

// cst --> cycle starting node
// clen --> cycle length

int solve() {
    int n, m, k;
    cin >> n >> m >> k;

    int hare = f(f(n % m, m), m), tort = f(n % m, m), cst = 0, clen = 1, kk;
    while (hare != tort) { // when hare == tort except starting node, a cycle exists
        hare = f(f(hare, m), m);
        tort = f(tort, m);
    }

    tort = n % m;
    while (hare != tort) { // two slow pointers from meeting point and start point end up at cycle starting point
        tort = f(tort, m);
        hare = f(hare, m);
        cst++;
    }

    hare = f(tort, m);
    while (tort != hare) { // cycle length calculation
        hare = f(hare, m);
        clen++;
    }

    if (k < cst) kk = k;
    else kk = (k - cst) % clen + cst;

    int ans = n % m;
    for (int i = 0; i < kk; i++) ans = f(ans, m);
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tt;
    cin >> tt;
    for (int tno = 1; tno <= tt; tno++) {
        cout << "Case #" << tno << ": " << solve() << "\n";
    }
}
