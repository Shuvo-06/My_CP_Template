#include <bits/stdc++.h>
using namespace std;

/*
size optimization
tuple <int, int, int> get_child(int idx, int lo, int hi) {
    int mid = lo + (hi - lo) / 2;
    return {mid, idx + 1, idx + 2 * (mid - lo + 1)};
}
*/

/*
Maximum subarray sum
Node pull(Node a, Node b) { // if non-empty sub-array only
    Node res;
    res.sum = a.sum + b.sum;
    res.lsum = max(a.lsum, a.sum + b.lsum);
    res.rsum = max(b.rsum, b.sum + a.rsum);
    res.best = max({res.sum, res.lsum, res.rsum, a.rsum + b.lsum, a.best, b.best});
    return res;
}
invalid return is (0, -inf, -inf, -inf)
*/

class SegmentTree {
private:
    struct Node {
        int val;
        Node() : val(0) {}
        Node(int val) : val(val) {}
    };

    int n;
    vector<Node> seg;

    Node pull(Node a, Node b) {
        Node res;
        res.val = a.val + b.val;
        return res;
    }

    tuple<int, int, int> get_child(int idx, int lo, int hi) {
        int mid = lo + (hi - lo) / 2;
        return {mid, idx + 1, idx + 2 * (mid - lo + 1)};
    }

    void build(int idx, vector<int> &v, int lo, int hi) {
        if (lo == hi) {
            seg[idx] = Node(v[lo]);
            return;
        }

        auto [mid, lci, rci] = get_child(idx, lo, hi);
        build(lci, v, lo, mid);
        build(rci, v, mid + 1, hi);
        seg[idx] = pull(seg[lci], seg[rci]);
    }

    void set(int idx, int pos, int val, int lo, int hi) {
        if (lo == hi) {
            seg[idx] = Node(val);
            return;
        }

        auto [mid, lci, rci] = get_child(idx, lo, hi);
        if (pos <= mid) set(lci, pos, val, lo, mid);
        else set(rci, pos, val, mid + 1, hi);
        seg[idx] = pull(seg[lci], seg[rci]);
    }

    Node query(int idx, int lo, int hi, int ql, int qr) {
        if (qr < lo || hi < ql) return Node(0);
        if (ql <= lo && hi <= qr) return seg[idx];

        auto [mid, lci, rci] = get_child(idx, lo, hi);
        Node q1 = query(lci, lo, mid, ql, qr);
        Node q2 = query(rci, mid + 1, hi, ql, qr);
        return pull(q1, q2);
    }

public:
    void build(vector<int> &v) {
        n = v.size();
        seg.assign(2 * n, Node());
        build(0, v, 0, n - 1);
    }

    void set(int pos, int val) {
        set(0, pos, val, 0, n - 1);
    }

    Node query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};

int main() {}
