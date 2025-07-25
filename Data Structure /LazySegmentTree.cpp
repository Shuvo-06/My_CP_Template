#include <bits/stdc++.h>
using namespace std;

class LazySegmentTree {
private: 
    int n;
    vector<long long> seg, lazy_add, lazy_set;
    vector<bool> set_pending;

    tuple<int, int, int> get_child(int idx, int lo, int hi) {
        int mid = lo + (hi - lo) / 2;
        return {mid, idx + 1, idx + 2 * (mid - lo + 1)};
    }

    void build(vector<long long> &v, int idx, int lo, int hi) {
        if (lo == hi) {
            seg[idx] = v[lo]; // change here if needed
            return;
        }

        auto [mid, lci, rci] = get_child(idx, lo, hi);
        build(v, lci, lo, mid);
        build(v, rci, mid + 1, hi);
        seg[idx] = seg[lci] + seg[rci]; // change here if needed
    }

    void assign(int idx, int lo, int hi, int val) {
        if (lo == hi) {
            seg[idx] = val;
            return;
        }

        auto [mid, lci, rci] = get_child(idx, lo, hi);
        assign(lci, lo, mid, val);
        assign(rci, mid + 1, hi, val);
        seg[idx] = seg[lci] + seg[rci]; // change here if needed
    }

    void push(int idx, int lo, int hi) {
        if (set_pending[idx]) {
            seg[idx] = lazy_set[idx] * (hi - lo + 1LL); // set entire segment
            if (lo != hi) {
                auto [mid, lci, rci] = get_child(idx, lo, hi);
                lazy_set[lci] = lazy_set[rci] = lazy_set[idx];
                set_pending[lci] = set_pending[rci] = true;
                lazy_add[lci] = lazy_add[rci] = 0;
            }
            lazy_set[idx] = 0;
            set_pending[idx] = false;
        }

        if (lazy_add[idx]) {
            seg[idx] += lazy_add[idx] * (hi - lo + 1LL);
            if (lo != hi) {
                auto [mid, lci, rci] = get_child(idx, lo, hi);
                lazy_add[lci] += lazy_add[idx];
                lazy_add[rci] += lazy_add[idx];
            }
            lazy_add[idx] = 0;
        }
    }

    void add(int idx, int clo, int chi, int qlo, int qhi, long long int val) {
        push(idx, clo, chi);
        if (chi < qlo || clo > qhi) return;
        if (qlo <= clo && chi <= qhi) {
            lazy_add[idx] += val; 
            push(idx, clo, chi);
            return;
        }

        auto [mid, lci, rci] = get_child(idx, clo, chi);
        add(lci, clo, mid, qlo, qhi, val);
        add(rci, mid + 1, chi, qlo, qhi, val); 
        seg[idx] = seg[lci] + seg[rci]; // change here if needed
    }

    void set(int idx, int clo, int chi, int qlo, int qhi, long long int val) {
        push(idx, clo, chi);
        if (chi < qlo || clo > qhi) return;
        if (qlo <= clo && chi <= qhi) {
            lazy_set[idx] = val;
            set_pending[idx] = true;
            lazy_add[idx] = 0;
            push(idx, clo, chi);
            return;
        }

        auto [mid, lci, rci] = get_child(idx, clo, chi);
        set(lci, clo, mid, qlo, qhi, val);
        set(rci, mid + 1, chi, qlo, qhi, val);
        seg[idx] = seg[lci] + seg[rci]; // change here if needed
    }

    long long int query(int idx, int clo, int chi, int qlo, int qhi) {
        push(idx, clo, chi);
        if (chi < qlo || clo > qhi) return 0LL; // change here if needed
        if (qlo <= clo && chi <= qhi) return seg[idx];

        auto [mid, lci, rci] = get_child(idx, clo, chi);
        auto q1 = query(lci, clo, mid, qlo, qhi);
        auto q2 = query(rci, mid + 1, chi, qlo, qhi);
        return q1 + q2; // change here if needed
    }

public: 
    void resize(int _n) { 
        n = _n; 
        seg.assign(2 * n, 0); 
        lazy_add.assign(2 * n, 0);
        lazy_set.assign(2 * n, 0);
        set_pending.assign(2 * n, false);
    }

    void assign(int _n, int val) { 
        n = _n; 
        seg.resize(2 * n); 
        lazy_add.resize(2 * n);
        assign(0, 0, n - 1, val);
    }

    void build(vector<long long> &v) { 
        n = v.size();
        seg.assign(2 * n, 0); 
        lazy_add.assign(2 * n, 0);
        lazy_set.assign(2 * n, 0);
        set_pending.assign(2 * n, false);
        build(v, 0, 0, n - 1); 
    }

    void add(int lo, int hi, long long val) { add(0, 0, n - 1, lo, hi, val); }
    void add(int pos, long long val) { add(0, 0, n - 1, pos, pos, val); }
    void set(int lo, int hi, long long val) { set(0, 0, n - 1, lo, hi, val); }
    void set(int pos, long long val) { set(0, 0, n - 1, pos, pos, val); }
    long long query(int lo, int hi) { return query(0, 0, n - 1, lo, hi); }
    long long query(int pos) { return query(0, 0, n - 1, pos, pos); }
};

/*
Lazy Segment tree
used for RU-PQ and RU-RQ
you can use it when operations are associative and distributive
Time complexity : 
    build : O(nlogn)
    rest of the operations are O(log N)
*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector <long long int> v(n);
    for (auto &x : v) cin >> x;
 
    LazySegmentTree st;
    st.build(v);
 
    while (q--) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1) {
            int x;
            cin >> x;
            st.add(l - 1, r - 1, x);
        }
        else if (op == 2) {
            int x;
            cin >> x;
            st.set(l - 1, r - 1, x);
        }
        else cout << st.query(l - 1, r - 1) << "\n";
    }
    return 0;
}
