#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private: 
    int n;
    vector<long long> seg;

    pair <int, int> get_child(int idx, int lo, int hi) {
        int mid = lo + (hi - lo) / 2;
        return {idx + 1, idx + 2 * (mid - lo + 1)};
    }

    void ibuild(int idx, vector<long long> &v, int lo, int hi) {
        if (lo == hi) {
            seg[idx] = v[lo]; // change if needed
            return;
        }

        int mid = lo + (hi - lo) / 2;
        auto [lci, rci] = get_child(idx, lo, hi);
        ibuild(lci, v, lo, mid);
        ibuild(rci, v, mid + 1, hi);
        seg[idx] = seg[lci] + seg[rci]; // change if needed
    }

    void iset(int idx, int pos, long long val, int lo, int hi) {
        if (lo == hi) {
            seg[idx] = val; // change if needed
            return;
        }

        int mid = lo + (hi - lo) / 2;
        auto [lci, rci] = get_child(idx, lo, hi);
        if (pos <= mid) iset(lci, pos, val, lo, mid);
        else iset(rci, pos, val, mid + 1, hi);
        seg[idx] = seg[lci] + seg[rci]; // change if needed
    }

    long long int iquery(int idx, int lo, int hi, int ql, int qr) {
        if (qr < lo || hi < ql) return 0LL; // change if needed
        if (ql <= lo && hi <= qr) return seg[idx]; // change if needed

        int mid = lo + (hi - lo) / 2;
        auto [lci, rci] = get_child(idx, lo, hi);
        auto left = iquery(lci, lo, mid, ql, qr);
        auto right = iquery(rci, mid + 1, hi, ql, qr);
        return left + right; // change if needed
    }

public: 
    SegmentTree(int _n) : n(_n) { seg.assign(2 * n, 0); }
    void build(vector<long long> &v) { ibuild(0, v, 0, n - 1); }
    void set(int pos, long long val) { iset(0, pos, val, 0, n - 1); }
    long long int query(int l, int r) { return iquery(0, 0, n - 1, l, r); }
    long long int query(int i) { return iquery(0, 0, n - 1, i, i); }
    void add(int pos, long long val) { set(pos, query(pos, pos) + val); }
};

int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    for (int tno = 1; tno <= tt; tno++) {
        cout << "Case " << tno << ": \n";
        
        int n, q;
        cin >> n >> q;
        vector <long long int> v(n);
        for (auto &x : v) cin >> x;
        SegmentTree st(n);
        st.build(v);
        
        while (q--) {
            int op;
            cin >> op;
            if (op == 1) {
                int i;
                cin >> i;
                cout << st.query(i) << "\n";
                st.set(i, 0LL);
            }
            else if (op == 2) {
                int i;
                long long int v;
                cin >> i >> v;
                st.add(i, v);
            }
            else {
                int l, r;
                cin >> l >> r;
                cout << st.query(l, r) << "\n";
            }
        }
    }
    return 0;
}
