#include <bits/stdc++.h>
using namespace std;

long long int digit_sum_till(long long int n) {
    if (n <= 0) return 0LL;
    long long int res = 0, factor = 1;
 
    while (factor <= n) {
        long long int higher = n / (factor * 10);
        long long int cur = (n / factor) % 10;
        long long int lower = n % factor;
 
        res += higher * 45 * factor;
 
        res += (cur * (cur - 1) / 2) * factor;
        res += cur * (lower + 1);
 
        factor *= 10;
    }
    return res;
}

long long int dig_count_till(long long int n) {
    if (n <= 9) return n;

    long long int ans = 0;
    for (long long int lo = 1, hi = 9, sz = 1;; hi = 10 * hi + 9, lo *= 10, sz++) {
        if (hi > n) {
            ans += (n - lo + 1) * sz;
            return ans;
        }
        else ans += (hi - lo + 1) * sz;
    }
}

int main() {

}
