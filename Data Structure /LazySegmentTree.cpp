#include <bits/stdc++.h>
using namespace std;

class LazySegmentTree {
private:
    int n;
    vector<long long int> seg, lazy_add, lazy_set;
    vector<bool> pending;

    tuple <int, int, int> get_child(int idx, int lo, int hi) {
        int mid = lo + (hi - lo) / 2;
        return {mid, idx + 1, idx + 2 * (mid - lo + 1)};
    }

    void push(int idx, int lo, int hi) {
        if (pending[idx]) {
            seg[idx] = (hi - lo + 1) * lazy_set[idx];
            if (lo != hi) {
                auto [mid, lci, rci] = get_child(idx, lo, hi);

                lazy_set[lci] = lazy_set[rci] = lazy_set[idx];
                pending[lci] = pending[rci] = true;
                lazy_add[lci] = lazy_add[rci] = 0;
            }
            pending[idx] = false;
            lazy_add[idx] = 0;
        }

        if (lazy_add[idx] != 0) {
            seg[idx] += (hi - lo + 1) * lazy_add[idx];
            if (lo != hi) {
                auto [mid, lci, rci] = get_child(idx, lo, hi);

                if (!pending[lci]) lazy_add[lci] += lazy_add[idx];
                else lazy_set[lci] += lazy_add[idx];

                if (!pending[rci]) lazy_add[rci] += lazy_add[idx];
                else lazy_set[rci] += lazy_add[idx];
            }
            lazy_add[idx] = 0;
        }
    }

    void build(int idx, vector<long long int> &v, int lo, int hi) {
        if (lo == hi) {
            seg[idx] = v[lo];
            return;
        }

        auto [mid, lci, rci] = get_child(idx, lo, hi);
        build(lci, v, lo, mid);
        build(rci, v, mid + 1, hi);
        seg[idx] = seg[lci] + seg[rci];
    }

    void update_set(int idx, int lo, int hi, int clo, int chi, long long int val) {
        push(idx, lo, hi);
        if (chi < lo || hi < clo) return;
        if (clo <= lo && hi <= chi) {
            lazy_set[idx] = val;
            pending[idx] = true;
            lazy_add[idx] = 0;
            push(idx, lo, hi);
            return;
        }

        auto [mid, lci, rci] = get_child(idx, lo, hi);
        update_set(lci, lo, mid, clo, chi, val);
        update_set(rci, mid + 1, hi, clo, chi, val);
        seg[idx] = seg[lci] + seg[rci];
    }

    void update_add(int idx, int lo, int hi, int clo, int chi, long long int val) {
        push(idx, lo, hi);
        if (chi < lo || hi < clo) return;
        if (clo <= lo && hi <= chi) {
            lazy_add[idx] += val;
            push(idx, lo, hi);
            return;
        }

        auto [mid, lci, rci] = get_child(idx, lo, hi);
        update_add(lci, lo, mid, clo, chi, val);
        update_add(rci, mid + 1, hi, clo, chi, val);
        seg[idx] = seg[lci] + seg[rci];
    }

    long long int query(int idx, int lo, int hi, int clo, int chi) {
        push(idx, lo, hi);
        if (chi < lo || hi < clo) return 0LL;
        if (clo <= lo && hi <= chi) return seg[idx];

        auto [mid, lci, rci] = get_child(idx, lo, hi);
        return query(lci, lo, mid, clo, chi) + query(rci, mid + 1, hi, clo, chi);
    }

public:
    LazySegmentTree(int _n) : n(_n) {
        seg.assign(2 * n, 0);
        lazy_add.assign(2 * n, 0);
        lazy_set.assign(2 * n, 0);
        pending.assign(2 * n, false);
    }

    void build(vector<long long int> &v) { build(0, v, 0, n - 1); }
    void set(int l, int r, long long int val) { update_set(0, 0, n - 1, l, r, val); }
    void add(int l, int r, long long int val) { update_add(0, 0, n - 1, l, r, val); }
    long long query(int l, int r) { return query(0, 0, n - 1, l, r); }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector <long long int> v(n);
    for (auto &x : v) cin >> x;

    LazySegmentTree st(n);
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
}
