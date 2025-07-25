#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private: 
    int n;
    vector<long long int> seg;

    tuple <int, int, int> get_child(int idx, int lo, int hi) {
        int mid = lo + (hi - lo) / 2;
        return {mid, idx + 1, idx + 2 * (mid - lo + 1)};
    }

    void build(int idx, vector<long long> &v, int lo, int hi) {
        if (lo == hi) {
            seg[idx] = v[lo]; // change if needed
            return;
        }

        auto [mid, lci, rci] = get_child(idx, lo, hi);
        build(lci, v, lo, mid);
        build(rci, v, mid + 1, hi);
        seg[idx] = seg[lci] + seg[rci]; // change if needed
    }

    void assign(int idx, int lo, int hi, int val) {
        if (lo == hi) {
            seg[idx] = val; // change if needed
            return;
        }

        auto [mid, lci, rci] = get_child(idx, lo, hi);
        assign(lci, lo, mid, val);
        assign(rci, mid + 1, hi, val);
        seg[idx] = seg[lci] + seg[rci]; // change if needed
    }

    void set(int idx, int pos, long long val, int lo, int hi) {
        if (lo == hi) {
            seg[idx] = val; // change if needed
            return;
        }

        auto [mid, lci, rci] = get_child(idx, lo, hi);
        if (pos <= mid) set(lci, pos, val, lo, mid);
        else set(rci, pos, val, mid + 1, hi);
        seg[idx] = seg[lci] + seg[rci]; // change if needed
    }

    long long int query(int idx, int lo, int hi, int ql, int qr) {
        if (qr < lo || hi < ql) return 0LL; // change if needed
        if (ql <= lo && hi <= qr) return seg[idx]; // change if needed

        auto [mid, lci, rci] = get_child(idx, lo, hi);
        auto q1 = query(lci, lo, mid, ql, qr);
        auto q2 = query(rci, mid + 1, hi, ql, qr);
        return q1 + q2; // change if needed
    }

public: 
    void assign(int _n, int val) {
        n = _n;
        seg.resize(2 * n);
        if (val != 0) assign(0, 0, n - 1, val);
    }

    void build(vector<long long int> &v) {
        n = v.size();
        seg.resize(2 * n);
        build(0, v, 0, n - 1); 
    }

    void add(int pos, long long val) { set(pos, query(pos, pos) + val); }
    void set(int pos, long long val) { set(0, pos, val, 0, n - 1); }
    long long int query(int l, int r) { return query(0, 0, n - 1, l, r); }
    long long int query(int i) { return query(0, 0, n - 1, i, i); }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifdef SUBLIME
        freopen("inputf.in", "r", stdin);
        freopen("outputf.out", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif

    int n, q;
    cin >> n >> q;

    SegmentTree st;
    st.assign(n + 1, 0);
 
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            st.add(l, x);
            st.add(r, -x);
        }
        else {
            int x;
            cin >> x;
            cout << st.query(0, x) << "\n";
        }
    }
    return 0;
}
