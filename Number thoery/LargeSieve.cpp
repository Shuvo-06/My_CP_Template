#include <bits/stdc++.h>
using namespace std;

const int N = 1e8;
bitset<N + 1> composite;

void sieve() {
    for (int i = 3; i * i <= N; i += 2)
        if (!composite[i])
            for (int j = i * i; j <= N; j += 2 * i)
                composite[j] = 1;
}

bool isPrime(int n) {
    return n == 2 || (n > 2 && (n & 1) && !composite[n]);
}

int32_t main() {
    sieve();

    cout << isPrime(97) << '\n';
    cout << isPrime(100) << '\n';
}
