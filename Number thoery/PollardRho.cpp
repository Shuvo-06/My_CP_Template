#include <bits/stdc++.h>
using namespace std;

using ll = long long;
namespace PollardRho {
    const int LIM = 1e6 + 9;
    int spf[LIM];                // smallest prime factor sieve
    vector<int> primes;
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

    // Modular arithmetic
    inline ll add_mod(ll a, ll b, ll m) {
        a += b;
        return a >= m ? a - m : a;
    }

    inline ll mul_mod(ll a, ll b, ll m) {
        return (ll)((__int128)a * b % m);
    }

    inline ll pow_mod(ll a, ll e, ll m) {
        ll res = 1 % m;
        while (e) {
            if (e & 1) res = mul_mod(res, a, m);
            a = mul_mod(a, a, m);
            e >>= 1;
        }
        return res;
    }

    // Simple deterministic Miller-Rabin for 64-bit
    bool isPrime(ll n) {
        if (n < 2) return false;
        for (ll p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
            if (n % p == 0) return n == p;

        ll d = n - 1, s = 0;
        while ((d & 1) == 0) d >>= 1, ++s;

        // Deterministic bases for 64-bit
        for (ll a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
            if (a % n == 0) continue;
            ll x = pow_mod(a, d, n);
            if (x == 1 || x == n - 1) continue;
            bool composite = true;
            for (int r = 1; r < s; ++r) {
                x = mul_mod(x, x, n);
                if (x == n - 1) {
                    composite = false;
                    break;
                }
            }
            if (composite) return false;
        }
        return true;
    }

    // Sieve initialization (small primes and smallest prime factors)
    void init() {
        for (int i = 2; i < LIM; ++i) {
            if (!spf[i]) spf[i] = i, primes.push_back(i);
            for (int p : primes) {
                if (p > spf[i] || 1LL * i * p >= LIM) break;
                spf[i * p] = p;
            }
        }
    }

    // Pollard-Rho algorithm for finding a nontrivial factor
    ll rho(ll n) {
        if (n % 2 == 0) return 2;
        while (true) {
            ll x = uniform_int_distribution<ll>(2, n - 2)(rng);
            ll y = x;
            ll c = uniform_int_distribution<ll>(1, n - 1)(rng);
            ll d = 1;
            while (d == 1) {
                x = add_mod(mul_mod(x, x, n), c, n);
                y = add_mod(mul_mod(y, y, n), c, n);
                y = add_mod(mul_mod(y, y, n), c, n);
                d = gcd(abs(x - y), n);
            }
            if (d != n) return d;
        }
    }

    // Factorization using Pollard-Rho + Miller-Rabin
    vector<ll> factorize(ll n) {
        if (n == 1) return {};
        if (n < LIM) {
            vector<ll> res;
            while (n > 1) {
                res.push_back(spf[n]);
                n /= spf[n];
            }
            return res;
        }
        if (isPrime(n)) return {n};
        ll d = rho(n);
        auto left = factorize(d);
        auto right = factorize(n / d);
        left.insert(left.end(), right.begin(), right.end());
        return left;
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

    PollardRho::init();
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        auto f = PollardRho::factorize(n);
        sort(f.begin(), f.end());
        cout << f.size() << '\n';
        for (ll x : f) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
