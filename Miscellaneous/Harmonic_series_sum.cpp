#include <bits/stdc++.h>
using namespace std;

// Harmonic series sum calculator : n (1 + 1/2 + 1/3 + .... 1/inf)
// Time complexity : O(sqrt(n))
long long int harmonic_sum(long long int n) {
    long long int res = 0, lo = 1;
    while (i <= n) {
        long long int val = n / i, hi = n / q;
        res += val * (hi - lo + 1);
        lo = hi + 1;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    cout << harmonic_sum(n) << endl;
    return 0;
}
