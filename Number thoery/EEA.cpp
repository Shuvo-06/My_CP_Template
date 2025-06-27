#include <bits/stdc++/h>
using namespace std;

// ax + by = c
// input (a, b). output (x, y, c)
// Or input (x, y). output (a, b, c)
// Time complexity : O(log n)
tuple<ll, ll, ll> eea(ll a, ll b) {
    if (b == 0) return {1, 0, a};
    auto [x, y, d] = eea(b, a % b);
    return {y, x - (a / b) * y, d};
}


int main() {
    
}
