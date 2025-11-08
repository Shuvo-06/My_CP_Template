#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXA = 1000000; // max value in array (adjust if needed)

vector<int> mu(MAXA + 1), primes;
vector<bool> isComp(MAXA + 1);

void mobius_sieve() {
    mu[1] = 1;
    for (int i = 2; i <= MAXA; i++) {
        if (!isComp[i]) {
            primes.push_back(i);
            mu[i] = -1;
        }
        for (int p : primes) {
            if (i * p > MAXA) break;
            isComp[i * p] = true;
            if (i % p == 0) {
                mu[i * p] = 0;
                break;
            } else {
                mu[i * p] = -mu[i];
            }
        }
    }
}

int countCoprimePairs(const vector<int>& a) {
    vector<int> freq(MAXA + 1, 0);
    for (int x : a) if (x <= MAXA) freq[x]++;

    vector<int> cnt(MAXA + 1, 0);
    for (int i = 1; i <= MAXA; i++)
        for (int j = i; j <= MAXA; j += i)
            cnt[i] += freq[j];

    int total = 0;
    for (int i = 1; i <= MAXA; i++) {
        if (mu[i] == 0) continue;
        int c = cnt[i];
        total += mu[i] * c * (c - 1) / 2;
    }

    return total;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    mobius_sieve(); // prepare once

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    cout << countCoprimePairs(a) << "\n";
}
