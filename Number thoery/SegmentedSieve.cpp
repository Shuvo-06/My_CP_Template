#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> primes;

void sieve(int n) {
    vector<bool> composite(n + 1);

    for (int i = 2; i * i <= n; i++)
        if (!composite[i])
            for (int j = i * i; j <= n; j += i)
                composite[j] = 1;

    for (int i = 2; i <= n; i++)
        if (!composite[i])
            primes.push_back(i);
}

vector<int> segmentedSieve(int L, int R) {
    vector<bool> composite(R - L + 1);

    for (int p : primes) {
        if (p * p > R) break;

        int start = max(p * p, (L + p - 1) / p * p);

        for (int j = start; j <= R; j += p)
            composite[j - L] = 1;
    }

    vector<int> ans;

    for (int i = L; i <= R; i++)
        if (i > 1 && !composite[i - L])
            ans.push_back(i);

    return ans;
}

signed main() {
    int L, R;
    cin >> L >> R;

    sieve(sqrtl(R));

    auto primes = segmentedSieve(L, R);

    for (int p : primes)
        cout << p << ' ';
}
