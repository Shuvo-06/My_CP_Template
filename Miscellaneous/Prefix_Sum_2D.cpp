#include <bits/stdc++.h>
using namespace std;

class Prefix2D {
private:
    int n, m;
    vector <vector<long long int>> prefix;

public:
    Prefix2D(vector< vector <long long int>> &grid) {
        n = grid.size();
        m = grid[0].size();
        prefix.assign(n + 1, std::vector<long long int>(m + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                prefix[i][j] = grid[i - 1][j - 1] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
            }
        }
    }

    // sum from top left (x1, y1) to bottom right (x2, y2) // 0 - based
    long long int query(int x1, int y1, int x2, int y2) {
        x1++, y1++, x2++, y2++;
        return prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1];
    }
};

int main() {
  // used to calculate prefix sum on 2D array
  // time complexity -> O(n * m + q) 
  
  int n,m;
  cin >> n >> m;
  vector <vector<long long int>> a(n, vector<long long int>(m));
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  }

  Prefix2D pref(a);
  
  int q;
  cin >> q;
  while (q--){
    int x1, y1, x2, y2;
    cin >> r1 >> c1 >> r2 >> c2;
    cout << pref.query(x1, y1, x2, y2) << "\n";
  }
  return 0;
}
