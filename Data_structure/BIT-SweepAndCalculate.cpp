#include <bits/stdc++.h>
using namespace std;

class BIT {
    int n;
    vector<long long> bit;

public:
    BIT(int n) : n(n), bit(n + 1) {}

    void add(int i, long long x) {
        for (++i; i <= n; i += i & -i) bit[i] += x;
    }

    long long query(int i) {
        long long ans = 0;
        for (; i; i -= i & -i) ans += bit[i];
        return ans;
    }

    long long query(int l, int r) {
        return query(r) - query(l);
    }
};

struct Point {
    int x, y;
    long long w;
};

struct Query {
    int x, d, u, id, sign;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<Point> p(n);
    vector<int> ys;

    for (auto &[x, y, w] : p) {
        cin >> x >> y >> w;
        ys.push_back(y);
    }

    vector<Query> qs(2 * q);

    for (int i = 0; i < q; i++) {
        int l, d, r, u;
        cin >> l >> d >> r >> u;

        qs[2 * i] = {r, d, u, i, 1};
        qs[2 * i + 1] = {l, d, u, i, -1};
    }

    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    sort(p.begin(), p.end(), [](auto &a, auto &b) {
        return a.x < b.x;
    });

    sort(qs.begin(), qs.end(), [](auto &a, auto &b) {
        return a.x < b.x;
    });

    BIT bit(ys.size());
    vector<long long> ans(q);

    int j = 0;

    for (auto [x, d, u, id, sign] : qs) {
        while (j < n && p[j].x < x) {
            int y = lower_bound(ys.begin(), ys.end(), p[j].y) - ys.begin();
            bit.add(y, p[j].w);
            j++;
        }

        int l = lower_bound(ys.begin(), ys.end(), d) - ys.begin();
        int r = lower_bound(ys.begin(), ys.end(), u) - ys.begin();

        ans[id] += sign * bit.query(l, r);
    }

    for (auto x : ans)
        cout << x << '\n';
}
