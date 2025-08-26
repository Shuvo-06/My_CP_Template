#include <bits/stdc++.h>
using namespace std;

template <typename T>
class SparseTable {
    vector<vector<T>> st;
    vector<int> lg;
    function<T(const T&, const T&)> f;
    int n, K;

public:
    SparseTable(vector<T>& v, function <T (const T&, const T&)> op) {
        f = op;
        n = v.size();
        if (n == 0) { 
            K = 0; 
            return;
        }


        K = 32 - __builtin_clz(n);
        st.assign(K, vector<T>(n));
        st[0] = v;

        for (int k = 1; k < K; ++k) {
            int len = 1 << k;
            int half = len >> 1;
            for (int i = 0; i + len <= n; i++) {
                st[k][i] = f(st[k-1][i], st[k-1][i + half]);
            }
        }
    }

    T query(int l, int r) {
        int k = 31 - __builtin_clz(r - l + 1);
        return f(st[k][l], st[k][r - (1 << k) + 1]);
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
