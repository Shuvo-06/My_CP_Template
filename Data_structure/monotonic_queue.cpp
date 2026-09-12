#include <bits/stdc++.h>
using namespace std;

// used for sliding window
// can find min/max in O(1) while traversing through the array in O(n)
// following code find minimum value and xor's them
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n, k;
    cin >> n >> k;
    int x, a, b, c;
    cin >> x >> a >> b >> c;
 
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        if (i == 0) v[i] = x;
        else v[i] = (1LL * v[i - 1] * a + b) % c;
    }
 
    int ans = 0;
    deque<int> d;
    for (int i = 0; i < n; i++) {
        while (!d.empty() && d.front() <= i - k) d.pop_front();
        while (!d.empty() && (v[d.back()] >= v[i] || d.back() <= i - k)) d.pop_back();
        d.push_back(i);
 
        if (i >= k - 1) ans ^= v[d.front()];
    }
 
    cout << ans << "\n";
    return 0;
}
