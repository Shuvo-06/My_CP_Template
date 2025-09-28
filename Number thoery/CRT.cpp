#include <bits/stdc++.h>
using namespace std;

#define int long long int
int phi_of(int n) {
    int res = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            res -= res / i;
        }
    }
    if (n > 1) res -= res / n;
    return res;
}

int inv(int a, int mod) {
    int ans = 1 % mod, b = phi_of(mod) - 1;
    while (b) {
        if (b & 1) ans= (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

pair<int, int> crt(int a, int m, int b, int n) {
    int g = __gcd(m, n);
    if ((b - a) % g != 0) return {0, -1};

    int lcm = m / g * n;
    int m1 = m / g, n1 = n / g;
    int t = ((b - a) / g) % n1 * inv(m1, n1) % n1;
    if (t < 0) t += n1;
    int x = (a + m * t) % lcm;
    if (x < 0) x += lcm;
    return {x, lcm};
}


int32_t main() {
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
        int a, n, b, m;
        cin >> a >> n >> b >> m;

        auto ans = crt(a, n, b, m);
        if (ans.second == -1) cout << "no solution\n";
        else cout << ans.first << " " << ans.second << "\n";
    }
}
