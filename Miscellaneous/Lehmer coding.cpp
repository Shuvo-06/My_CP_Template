#include <bits/stdc++.h>
using namespace std;

namespace Lehmer {
    int n;
    vector<int> f;

    void init(int _n) {
        n = _n;
        f.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) f[i] = f[i - 1] * i;
    }

    int encode(const vector<int>& p) {
        int r = 0;
        for (int i = 0; i < n; i++) {
            int c = 0;
            for (int j = i + 1; j < n; j++)
                if (p[j] < p[i]) c++;
            r += c * f[n - 1 - i];
        }
        return r;
    }

    vector<int> decode(int r) {
        vector<int> a(n);
        iota(a.begin(), a.end(), 1);

        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            int idx = r / f[n - 1 - i];
            r %= f[n - 1 - i];
            p[i] = a[idx];
            a.erase(a.begin() + idx);
        }
        return p;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef SUBLIME
        freopen("inputf.in", "r", stdin);
        freopen("outputf.out", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif

    Lehmer :: init(9);

    return 0;
}
