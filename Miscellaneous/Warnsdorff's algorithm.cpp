#include <bits/stdc++.h>
using namespace std;

struct position { 
    int x, y, z; 
};

vector<tuple <int, int, int>> moves = {
    {-2, -1, 0}, 
    {-2, 0, -1}, 
    {-2, 0, 1}, 
    {-2, 1, 0},
    {-1, -2, 0}, 
    {-1, 0, -2}, 
    {-1, 0, 2}, 
    {-1, 2, 0},
    {0, -2, -1}, 
    {0, -2, 1}, 
    {0, -1, -2}, 
    {0, -1, 2},
    {0,  1, -2}, 
    {0,  1,  2}, 
    {0,  2, -1}, 
    {0,  2,  1},
    {1, -2, 0},  
    {1, 0, -2},  
    {1, 0,  2},  
    {1, 2, 0},
    {2, -1, 0},  
    {2, 0, -1},  
    {2, 0,  1},  
    {2, 1, 0}
};

int a, b, c;
vector<vector<vector<int>>> vis;

bool in_bound(int x, int y, int z) {
    return (x >= 1 && y >= 1 && z >= 1 && x <= a && y <= b && z <= c);
}

int degree(int x, int y, int z) {
    int cnt = 0;
    for (auto [dx, dy, dz] : moves) {
        int nx = x + dx, ny = y + dy, nz = z + dz;
        if (in_bound(nx, ny, nz) && !vis[nx][ny][nz]) cnt++;
    }
    return cnt;
}

double dis(int x, int y, int z) {
    double cx = (a + 1) / 2.0;
    double cy = (b + 1) / 2.0;
    double cz = (c + 1) / 2.0;
    return sqrt((x - cx)*(x - cx) + (y - cy)*(y - cy) + (z - cz)*(z - cz));
}

bool tour(int sx, int sy, int sz, vector<position> &path) {
    int x = sx, y = sy, z = sz;
    vis[x][y][z] = true;
    path.push_back({x, y, z});

    for (int step = 1; step < a * b * c; step++) {
        vector<pair<int, position>> cand;
        for (auto [dx, dy, dz] : moves) {
            int nx = x + dx, ny = y + dy, nz = z + dz;
            if (in_bound(nx, ny, nz) && !vis[nx][ny][nz]) cand.push_back({degree(nx, ny, nz), {nx, ny, nz}});
        }
        if (cand.empty()) return false;

        sort(cand.begin(), cand.end(), [&](auto &p, auto &q) {
            if (p.first != q.first) return p.first < q.first;
            return dis(p.second.x, p.second.y, p.second.z) > dis(q.second.x, q.second.y, q.second.z);
        });

        x = cand[0].second.x;
        y = cand[0].second.y;
        z = cand[0].second.z;
        vis[x][y][z] = true;
        path.push_back(cand[0].second);
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b >> c;
    vis.assign(a + 1, vector<vector<int>>(b + 1, vector<int>(c + 1, 0)));

    vector<position> path;
    if (tour(1, 1, 1, path)) {
        cout << "YES\n";
        for (auto pos : path) cout << pos.x << " " << pos.y << " " << pos.z << "\n";
    } 
    else cout << "NO\n";
    return 0;
}
