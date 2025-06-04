#include <bits/stdc++.h>
using namespace std;

// calculates Euler's phi function's value for one single element
// Time complexity : O(sqrt(n))

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

// 1139 - 1219 ms for n = 1e8
// 109 - 140 ms for n = 1e7
// 8 - 15 ms for n = 1e6
// calculates Euler's phi function for all values from 1 to n
// Time complexity : O(n)

vector <int> phi;
void init_phi(int n) {
    vector<int> spf(n + 1), primes;
    phi.resize(n + 1),
    phi[0] = 0; phi[1] = 1;

    for (int i = 2; i <= n; ++i) {
        if (spf[i] == 0) {
            spf[i] = i;
            phi[i] = i - 1;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > spf[i] || i * p > n) break;
            spf[i * p] = p;
            phi[i * p] = phi[i] * (p - (i % p != 0));
        }
    }
    return;
}

/*
// memory efficient function
// Time complexity : O(nlogn)
void init_phi(int n) {
    phi.resize(n + 1);
    iota(phi.begin(), phi.end(), 0);

    for (int i = 2; i <= n; ++i) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i) phi[j] -= phi[j] / i;
        }
    }
}
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);



    return 0;
}
