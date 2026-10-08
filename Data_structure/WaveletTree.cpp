#include <bits/stdc++.h>
using namespace std;

class WaveletTree {
    struct Node {
        int lo, hi;
        vector<int> pref;
        vector<long long> sum;
        Node *l = nullptr, *r = nullptr;

        Node(int lo, int hi) : lo(lo), hi(hi) {}
    };

    Node *root;

    Node* build(vector<int> &a, int lo, int hi) {
        Node *t = new Node(lo, hi);

        if (lo == hi) return t;

        int mid = (lo + hi) / 2;
        vector<int> L, R;

        t->pref.push_back(0);
        t->sum.push_back(0);

        for (int x : a) {
            t->pref.push_back(t->pref.back() + (x <= mid));
            t->sum.push_back(t->sum.back() + x);

            if (x <= mid) L.push_back(x);
            else R.push_back(x);
        }

        t->l = build(L, lo, mid);
        t->r = build(R, mid + 1, hi);

        return t;
    }

    int kth(Node *t, int l, int r, int k) {
        if (t->lo == t->hi) return t->lo;

        int cnt = t->pref[r] - t->pref[l];
        int lb = t->pref[l], rb = t->pref[r];

        if (k <= cnt)
            return kth(t->l, lb, rb, k);

        return kth(t->r, l - lb, r - rb, k - cnt);
    }

    int count(Node *t, int l, int r, int x) {
        if (l >= r || x < t->lo) return 0;
        if (t->hi <= x) return r - l;

        int lb = t->pref[l], rb = t->pref[r];

        return count(t->l, lb, rb, x)
             + count(t->r, l - lb, r - rb, x);
    }

    long long sum(Node *t, int l, int r, int x) {
        if (l >= r || x < t->lo) return 0;
        if (t->hi <= x) return t->sum[r] - t->sum[l];

        int lb = t->pref[l], rb = t->pref[r];

        return sum(t->l, lb, rb, x)
             + sum(t->r, l - lb, r - rb, x);
    }

public:
    WaveletTree(vector<int> a) {
        int lo = *min_element(a.begin(), a.end());
        int hi = *max_element(a.begin(), a.end());
        root = build(a, lo, hi);
    }

    int kth(int l, int r, int k) {
        return kth(root, l, r, k);
    }

    int count(int l, int r, int x) {
        return count(root, l, r, x);
    }

    long long sum(int l, int r, int x) {
        return sum(root, l, r, x);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> a = {5, 1, 7, 3, 9, 2, 6};

    WaveletTree wt(a);

    cout << wt.kth(1, 6, 2) << '\n';       // 2nd smallest
    cout << wt.count(1, 6, 5) << '\n';     // count <= 5
    cout << wt.sum(1, 6, 5) << '\n';       // sum of values <= 5
}
