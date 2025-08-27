#include <bits/stdc++.h>
using namespace std;

template <typename T>
class SparseTable {
    vector<vector<T>> st;
    vector<int> lg;
    function<T(const T&, const T&)> f;
    int n, K;

public:
    SparseTable(const vector<T>& v, function<T(const T&, const T&)> op) {
        f = op;
        n = v.size();
        if (n == 0) {
            K = 0;
            return;
        }

        K = 32 - __builtin_clz(n);
        st.assign(n, vector<T>(K));
        lg.assign(n + 1, 0);

        for (int i = 0; i < n; i++) st[i][0] = v[i];

        for (int j = 1; j < K; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = f(st[i][j-1], st[i + (1 << (j-1))][j-1]);
            }
        }
    }


    T query(int l, int r) {
        int k = 31 - __builtin_clz(r - l + 1);
        return f(st[l][k], st[r - (1 << k)][k]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr );

    #ifdef SUBLIME
        freopen("inputf.in", "r", stdin);
        freopen("outputf.out", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif
        
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (auto &x : v) cin >> x;

    SparseTable<int> st(v, [](const int& a, const int& b) {
        return min(a, b);
    });

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        cout << st.query(l, r) << "\n";
    }
    return 0;
}
