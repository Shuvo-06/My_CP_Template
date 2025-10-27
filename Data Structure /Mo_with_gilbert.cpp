#include <bits/stdc++.h>
using namespace std;

inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
    if (pow == 0) return 0;
    
    int hpow = 1 << (pow-1);
    int seg = (x < hpow) ? ( (y < hpow) ? 0 : 3) : ((y < hpow) ? 1 : 2);
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int64_t subSquareSize = int64_t(1) << (2*pow - 2);
    int64_t ans = seg * subSquareSize;
    int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}

struct Query {
    int l, r, idx;
    int64_t ord;
 
    inline void calcOrder() {
        ord = gilbertOrder(l, r, 21, 0);
    }
};

inline bool operator<(const Query &a, const Query &b) {
    return a.ord < b.ord;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    #ifdef SUBLIME
        freopen("inputf.in", "r", stdin);
        freopen("outputf.out", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif

    int n, q;
    cin >> n >> q;
    vector<int> a(n), values;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        values.push_back(a[i]);
    }

    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--;
        queries[i].r--;
        queries[i].idx = i;
        queries[i].calcOrder();
    }

    sort(queries.begin(), queries.end());

    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    for (int &x : a) x = lower_bound(values.begin(), values.end(), x) - values.begin();

    static int freq[200005];

    vector<int> ans(q);
    int curL = 0, curR = -1, distinct = 0;

    for (auto &query : queries) {
        while (curL > query.l) {
            curL--;
            if (freq[a[curL]]++ == 0) distinct++;
        }
        while (curR < query.r) {
            curR++;
            if (freq[a[curR]]++ == 0) distinct++;
        }
        while (curL < query.l) {
            if (--freq[a[curL]] == 0) distinct--;
            curL++;
        }
        while (curR > query.r) {
            if (--freq[a[curR]] == 0) distinct--;
            curR--;
        }
        ans[query.idx] = distinct;
    }

    for (int x : ans) cout << x << "\n";
}
