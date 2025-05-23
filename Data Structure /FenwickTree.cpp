#include <bits/stdc++.h>
using namespace std;

/*
Binary Indexed Tree (Fenwick Tree)
----------------------------------
Supports:
- add(i, val): add to index i
- set(i, val): set index i to val
- add(l, r, val): add val to range [l, r]
- query(i): value at index i
- query(l, r): range sum [l, r]
- find_kth(k): smallest index with prefix sum ≥ k

Time: O(log N) per operation, O(N) build.

Edge Cases:
-----------
- 0-based input, internally 1-based.
- Ensure 0 ≤ i, l, r < n.
- Works with negatives & zeros.
- find_kth assumes non-negative prefix sums.
*/

template <class T>
struct BIT {
    int n;
    vector <T> bit;

    BIT() {}
    BIT(vector<T> &v) {
        n = v.size();
        bit.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            add(i, i, v[i]); // for RU-PQ
            // add(i, v[i]); // for PU-RQ
        }
    }

    T ipsum(int i) {
        T ans = 0;
        for (; i; i -= (i & -i)) ans += bit[i];
        return ans;
    }

    T pref_sum(int i) {
        return ipsum(i + 1);
    }

    void add(int i, T val) {
        i++;
        for (; i < (int)bit.size(); i += (i & -i)) bit[i] += val;
    }

    void add(int l, int r, T val) {
        add(l, val);
        add(r + 1, -val);
    }

    void set(int i, T val) {
        add(i, val - query(i));
    }

    T query(int l, int r) {
        return pref_sum(r) - pref_sum(l - 1);
    }

    T query(int i) {
        return pref_sum(i) - pref_sum(i - 1);
    }

    int find_kth(T k) {
        int idx = 0, bitMask = 1;
        while (bitMask <= n) bitMask <<= 1;
        for (int step = bitMask; step > 0; step >>= 1) {
            int nextIdx = idx + step;
            if (nextIdx <= n && bit[nextIdx] < k) {
                k -= bit[nextIdx];
                idx = nextIdx;
            }
        }
        return idx;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE 
        freopen("inputf.in", "r", stdin);
        freopen("outputf.out", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif
    
    int n, q;
    cin >> n >> q;
    vector <long long int> v(n);
    for (auto &x : v) cin >> x;

    BIT <long long int> bit(v);

    return 0;
}
