#include <bits/stdc++.h>
using namespace std;


/*
Binary Indexed Tree aka Fenwick Tree
- Construction: O(N)
- query, add: O(log N)
- find_kth: O(log N) — find smallest index with prefix sum >= k
Note:
- add(i, val): adds val to element at index i
- set(i, val): sets element at index i to val (requires current value)
- addr(l, r, val): adds val to range [l, r]
*/

template <class T>
struct BIT {
    int n;
    vector<T> bit;

    BIT() {}
    BIT(int _n) {
        n = _n;
        bit.assign(n + 1, 0);
    }


    T query(int i) {
        T ans = 0;
        for (; i >= 1; i -= (i & -i)) ans += bit[i];
        return ans;
    }

    void add(int i, T val) {
        if (i <= 0) return;
        for (; i <= n; i += (i & -i)) bit[i] += val;
    }

    void addr(int l, int r, T val) {
        add(l, val);
        add(r + 1, -val);
    }

    void set(int i, T val) {
        T current = query(i) - query(i - 1);
        add(i, val - current);
    }

    T query(int l, int r) {
        return query(r) - query(l - 1);
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
        return idx + 1;
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
    
    vector <int> arr = {0, 3, 2, -1, 6, 5, 4, -3, 3, 7, 2};

    int n = (int)arr.size();
    BIT <int> bit(n);

    for (int i = 1; i <= n; i++) bit.add(i, arr[i]);

    cout << "Prefix sum (1..5): " << bit.query(5) << "\n"; // Expected: 3+2+(-1)+6+5=15
    cout << "Range sum (3..7): " << bit.query(3, 7) << "\n"; // Expected: (-1)+6+5+4+(-3) = 11

    // Point update: add 2 to index 4
    bit.add(4, 2);
    cout << "After adding 2 to index 4, value at 4: " << bit.query(4, 4) << "\n"; // Expected: 6+2=8

    // Range add: add 3 to elements from index 2 to 5
    bit.addr(2, 5, 3);
    cout << "After adding 3 to range [2..5], range sum (1..5): " << bit.query(1, 5) << "\n";

    // Set value at index 3 to 10
    bit.set(3, 10);
    cout << "After setting index 3 to 10, value at 3: " << bit.query(3, 3) << "\n"; // 10

    // Use find_kth: find smallest index where prefix sum >= 20
    int idx = bit.find_kth(20);
    cout << "Smallest index with prefix sum >= 20: " << idx << "\n";

    return 0;
}
