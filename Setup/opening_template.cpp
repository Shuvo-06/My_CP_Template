#include <bits/stdc++.h>
using namespace std;

#define rounded(a,b) ((a + (b / 2)) / b)
#define ceiled(a,b) ((a + b - 1) / b)
#define unify(v) sort(v.begin(), v.end());v.erase(unique(v.begin(), v.end()), v.end());
// clamp(val, lo, hi) -> returns restricted given value
// --lg2(val) - log2(val) 
// bit_width(val)

int isqrt(int x) {
    int l = 0, r = x, ans = 0;
    while (l <= r) {
        int m = (l + r) / 2;
        if (m * m <= x) ans = m, l = m + 1;
        else r = m - 1;
    }
    return ans;
}

int isqrtl(int x) {
    int r = sqrtl(x);
    while ((r + 1) * (r + 1) <= x) r++;
    while (r * r > x) r--;
    return r;
}

int cir(vector<int>& v, int l, int r) {
    return upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l);
}

// --- Grid Movement ---
#define in_bound(x, y, n, m) (x >= 0 && x < n && y >= 0 && y < m)
vector<pair<int, int>> moves4 = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; string moves4c = "UDLR";
vector<pair<int, int>> moves8 = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
vector<pair<int, int>> knight = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    #ifdef SUBLIME
        freopen("inputf.in", "r", stdin);
        freopen("outputf.out", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif

    // code here

    return 0;
}
