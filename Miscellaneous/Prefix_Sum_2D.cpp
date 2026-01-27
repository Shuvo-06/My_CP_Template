#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " -> " << x << endl;

#define in_bound(i, j, n, m) (i >= 0 && j >= 0 && i < n && j < m)

class Query {
public :
    int x1, y1, x2, y2;

    Query(int _x1, int _y1, int _x2, int _y2) : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}
    Query() { x1 = 0, y1 = 0, x2 = 0, y2 = 0; }
};

void diff_upd(vector<vector<int>> &v, Query &q, int val) {
    int n = v.size(), m = v[0].size();

    v[q.x1][q.y1] += val;
    if (in_bound(q.x1, q.y2 + 1, n, m)) v[q.x1][q.y2 + 1] -= val;
    if (in_bound(q.x2 + 1, q.y1, n, m)) v[q.x2 + 1][q.y1] -= val;
    if (in_bound(q.x2 + 1, q.y2 + 1, n, m)) v[q.x2 + 1][q.y2 + 1] += val;
}

void build(vector<vector<int>> &v) {
    int n = v.size(), m = v[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (in_bound(i - 1, j, n, m)) v[i][j] += v[i - 1][j];
            if (in_bound(i, j - 1, n, m)) v[i][j] += v[i][j - 1];
            if (in_bound(i - 1, j - 1, n, m)) v[i][j] -= v[i - 1][j - 1];
        }
    }
}

int query(vector<vector<int>> &v, Query &q) {
    int n = v.size(), m = v[0].size();

    int res = v[q.x2][q.y2];
    if (in_bound(q.x1 - 1, q.y2, n, m)) res -= v[q.x1 - 1][q.y2];
    if (in_bound(q.x2, q.y1 - 1, n, m)) res -= v[q.x2][q.y1 - 1];
    if (in_bound(q.x1 - 1, q.y1 - 1, n, m)) res += v[q.x1 - 1][q.y1 - 1];
    return res;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef SUBLIME
        freopen("inputf.in", "r", stdin);
        freopen("outputf.out", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif

    vector <vector <int>>  v(2000, vector <int> (2000, 0)), solos(2000, vector <int> (2000, 0));;

    int n;
    cin >> n;

    vector <Query> clouds(n);
    for (auto &x : clouds) {
        int u, d, l, r;
        cin >> u >> d >> l >> r;
        u--; d--; l--; r--;

        x = Query {u, l, d, r};
        diff_upd(v, x, 1);
    }

    build(v);

    int ind = 0;
    for (int i = 0; i < 2000; i++) {
        for (int j = 0; j < 2000; j++) {
            ind += (v[i][j] == 0);
            solos[i][j] = (v[i][j] == 1);
        }
    }

    build(solos);

    for (auto &x : clouds) cout << ind + query(solos, x) << "\n";
    return 0;
}
