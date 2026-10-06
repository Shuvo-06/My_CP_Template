#include <bits/stdc++.h>
using namespace std;

// 1. Minimum XOR pair
int min_xor_pair(vector<int> &a) {
    sort(a.begin(), a.end());
    int ans = LLONG_MAX;
    for (int i = 1; i < a.size(); i++) ans = min(ans, a[i] ^ a[i - 1]);
    return ans;
}

// 2. Maximum XOR pair
int max_xor_pair(vector<int> &a) {
    int ans = 0;
    for (int x : a) {
        int cur = 0;
        for (int b = 30; b >= 0; b--) {
            int want = (cur ^ (1 << b));
            bool ok = false;
            for (int y : a) {
                if ((y & (1 << b)) != (x & (1 << b))) {
                    ok = true;
                    break;
                }
            }
            if (ok) cur = want;
        }
        ans = max(ans, cur);
    }
    return ans;
}

// 3. Minimum XOR subarray
int min_xor_subarray(vector<int> &a) {
    int n = a.size();
    vector <int> p(n + 1);
    for (int i = 0; i < n; i++) p[i + 1] = p[i] ^ a[i];
    return min_xor_pair(p);
}

// 4. Minimum XOR of (OR) and (AND) over a pair
int min_xor_or_and(vector<int> &a) {
    return min_xor_pair(a);
}

// 5. Maximum XOR of any subsequence
int max_xor_subsequence(vector<int> &a) {
    int basis[31] = {};
  
    for (int x : a) {
        for (int b = 30; b >= 0; b--) {
            if (!(x & (1 << b))) continue;
            if (!basis[b]) {
                basis[b] = x;
                break;
            }
            x ^= basis[b];
        }
    }

    int ans = 0;
    for (int b = 30; b >= 0; b--) ans = max(ans, ans ^ basis[b]);
    return ans;
}

// 6. Sum of XOR of all subsets
long long sum_subset_xor(vector<int> &a) {
    int n = a.size(), OR = 0;
    for (int x : a) OR |= x;
    return (1LL << (n - 1)) * OR;
}

// 7. Sum of OR of all subsets
long long sum_subset_or(vector<int> &a) {
    int n = a.size();
    long long ans = 0;

    for (int b = 0; b <= 30; b++) {
        int cnt = 0;
        for (int x : a) cnt += (x >> b) & 1;
        ans += (1LL << b) * ((1LL << n) - (1LL << (n - cnt)));
    }

    return ans;
}

// 8. Sum of AND of all non-empty subsets
long long sum_subset_and(vector<int> &a) {
    long long ans = 0;
    for (int b = 0; b <= 30; b++) {
        int cnt = 0;
        for (int x : a) cnt += (x >> b) & 1;
        ans += (1LL << b) * ((1LL << cnt) - 1);
    }
    return ans;
}

// 9. Maximum AND pair
int max_and_pair(vector<int> &a) {
    vector<int> cur = a;
    int ans = 0;
    for (int b = 30; b >= 0; b--) {
        vector<int> nxt;
        for (int x : cur) if (x & (1 << b)) nxt.push_back(x);

        if (nxt.size() >= 2) {
            ans |= 1 << b;
            cur = nxt;
        }
    }
    return ans;
}

int main() {}
