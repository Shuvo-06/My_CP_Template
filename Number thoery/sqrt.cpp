#include <bits/stdc++.h>
using namespace std;

#define int long long
int root(int n) {
    int ans = sqrt(n);
    while ((ans + 1) * (ans + 1) <= n) ans++;
    while (ans * ans > n) ans--;
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef SUBLIME
        freopen("inputf.in", "r", stdin);
        freopen("outputf.out", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif

    // n - (int)sqrt(n) == k

    int tt;
    cin >> tt;
    while (tt--) {
        int k;
        cin >> k;

        int lo = 1, hi = LLONG_MAX, ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            int on = mid - root(mid);
            
            if (on >= k) {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }

        cout << ans << "\n";
    }
    return 0;
}
