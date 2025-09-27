#include <bits/stdc++.h>
using namespace std;

// a ^ b = c (mod m)
// find smallest b
// Shank's BSGS

// Discrete logs : Discrete logs are same as basic math logs, but of modular arithmetic
// a ^ b = c (mod m)
// b = loga c (mod m)
// find smallest b using Shank's Baby step Giant step method

// assume that b = pn - q
// where n = sqrt(m) + 1, p = [1, ceil(m, n)], q = [0, n]
// for a, m to be co-prime, 
// we divide base, result and mod multiple time until they become co-prime
// if we can't divide when (a, m) is not co-prim,e, there's simply no solution

// now the form is alpha * a ^ (pn - q) = c (mod m) and (a, m) is co-prime and power is reduced cnt time
// this can be re-wriiten as alpha * (a ^ n) ^ p = c * a^q (mod m)
// so, now 
//          f(p) = alpha * (a ^ n) ^ p
// and      f(q) = c * (a ^ q)

// for smallest b, we need smallest p and biggest q
// so, we iterate q first and store in a map
// then, while iterating through p, if we find a match, that's the expected (p, q) pair


#define int long long int
int root(int x) {
    if (x <= 1) return x;
    int l = 0, r = x, ans = 0;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (m <= x / m) ans = m, l = m + 1;
        else r = m - 1;
    }
    return ans;
}

int pwr(int a, int b, int mod) {
    int ans = 1 % mod;
    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans % mod;
}

int discrete_log(int a, int c, int m) {
    a %= m;
    c %= m;

    int alpha = 1, gc, cnt = 0;
    while ((gc = __gcd(a, m)) != 1) {
        if (alpha == c) return cnt;
        if (c % gc != 0) return -1;

        c /= gc;
        m /= gc;
        cnt++;
        (alpha *= (a / gc)) %= m;
    }

    int n = root(m) + 1;
    unordered_map <int, int> vals;

    int an = pwr(a, n, m);

    for (int q = 0, val = c; q <= (m + n - 1) / n; q++) {
        vals[val] = q;
        val = (val * a) % m;
    }

    for (int p = 1, val = alpha; p <= n; p++) {
        (val *= an) %= m;
        if (vals.count(val) != 0) return p * n - vals[val] + cnt;
    }
    
    return -1;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x, z, k;
    while (true) {
        cin >> x >> z >> k;
        if (x == 0 && z == 0 && k == 0) break;

        int ans = discrete_log(x, k, z);
        if (ans == -1) cout << "No Solution\n";
        else cout << ans << "\n";
    }
}
