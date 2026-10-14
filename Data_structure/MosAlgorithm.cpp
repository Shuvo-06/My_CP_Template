
#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Query {
    int l, r, idx;
};

void mo_sort(vector<Query> &queries, int n) {
    int block = max(1LL, (int)sqrt(n));

    sort(queries.begin(), queries.end(), [block](const Query &a, const Query &b) {
        int blockA = a.l / block;
        int blockB = b.l / block;

        if (blockA != blockB) return blockA < blockB;

        return (blockA & 1) ? a.r > b.r : a.r < b.r;
    });
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    #ifdef SUBLIME
        freopen("inputf.in", "r", stdin);
        freopen("outputf.out", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif

    int n;
    cin >> n;

    vector<int> v(n);
    for (auto &x : v) cin >> x;

    int q;
    cin >> q;

    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        --queries[i].l;
        --queries[i].r;
        queries[i].idx = i;
    }

    mo_sort(queries, n);

    vector<int> vals = v;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    for (auto &x : v) {
        x = lower_bound(vals.begin(), vals.end(), x) - vals.begin();
    }

    vector<int> freq(vals.size());
    vector<int> ans(q);

    int curL = 0, curR = -1;
    int distinct = 0;

    auto add = [&](int pos) {
        if (freq[v[pos]] == 0) distinct++;
        freq[v[pos]]++;
    };

    auto remove = [&](int pos) {
        freq[v[pos]]--;
        if (freq[v[pos]] == 0) distinct--;
    };

    for (auto x : queries) {
        while (curL > x.l) add(--curL);
        while (curR < x.r) add(++curR);
        while (curL < x.l) remove(curL++);
        while (curR > x.r) remove(curR--);

        ans[x.idx] = distinct;
    }

    for (auto x : ans) cout << x << '\n';
}
