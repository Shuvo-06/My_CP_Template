#include <bits/stdc++.h>
using namespace std;

template <class T>
struct SegmentTree {
    int n;
    vector<T> seg;

    SegmentTree() {}
    SegmentTree(const vector<int> &v) {
        n = v.size();
        seg.resize(4 * n);
        build(v, 1, 0, n - 1);
    }

    void build(const vector<int> &v, int ind, int lo, int hi) {
        if (lo == hi) {
            seg[ind] = v[lo]; // change here
            return;
        }
        int mid = (lo + hi) / 2;
        build(v, 2 * ind, lo, mid);
        build(v, 2 * ind + 1, mid + 1, hi);
        seg[ind] = min(seg[2 * ind], seg[2 * ind + 1]); // change here
    }

    T query(int l, int r) {
        return iq(1, 0, n - 1, l, r);
    }

    void set(int pos, int val) {
        iu(1, 0, n - 1, pos, val);
    }

    T iq(int ind, int tl, int tr, int l, int r) {
        if (r < tl || tr < l) return INT_MAX; // change here
        if (l <= tl && tr <= r) return seg[ind]; // change here
        int tm = (tl + tr) / 2;
        return min(iq(2 * ind, tl, tm, l, r), iq(2 * ind + 1, tm + 1, tr, l, r)); // change here
    }

    void iu(int ind, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            seg[ind] = val; // change here
            return;
        }
        int tm = (tl + tr) / 2;
        if (pos <= tm) iu(2 * ind, tl, tm, pos, val);
        else iu(2 * ind + 1, tm + 1, tr, pos, val);
        seg[ind] = min(seg[2 * ind], seg[2 * ind + 1]); // change here
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector <int> v(n);
    for (auto &x : v) cin >> x;

    SegmentTree <int> st(v);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int k, u;
            cin >> k >> u;
            st.set(k - 1, u);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << st.query(l - 1, r - 1) << "\n";
        }
        
    }
    
    return 0;
}
