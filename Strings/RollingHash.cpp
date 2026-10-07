#include <bits/stdc++.h>
using namespace std;

// Rolling Hash
// get(l, r) -> hash of s[l...r-1]
//
// Complexity:
//   Build and Memory: O(n)
//   Query: O(1)
//
// Uses uint64_t overflow as modulo 2^64.
//
//   1. get(l, r) uses [l, r), not [l, r].
//   2. Hash equality is probabilistic; collisions are possible.
//   3. Use unsigned integer types for intentional overflow.
//   4. Use a reasonably large base; randomizing it is safer.
//   5. For highly adversarial problems, use double hashing.

struct Hash {
    using ull = unsigned long long;

    ull base = 911382323;
    vector<ull> h, p;

    Hash(string s) {
        int n = s.size();
        h.resize(n + 1);
        p.resize(n + 1, 1);

        for (int i = 0; i < n; i++) {
            h[i + 1] = h[i] * base + s[i];
            p[i + 1] = p[i] * base;
        }
    }

    ull get(int l, int r) {
        return h[r] - h[l] * p[r - l];
    }
};

int main() {
    string s = "abcabc";
    Hash hs(s);

    // Compare "abc" with "abc"
    cout << (hs.get(0, 3) == hs.get(3, 6)) << '\n';
}