#include <bits/stdc++.h>
using namespace std;


int main() {
  //used to calculate prefix sum on 2D array
  //time complexity -> O(n * m + q) 
  //top left corner -> (x1, y1)
  //bottom right corner -> (x2, y2)
  
  int n,m;
  cin >> n >> m;
  vector <vector<int>> pref(n + 1, vector<int>(m + 1, 0)), a(n, vector<int>(m));
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i][j];
    }
  }
  
  int q;
  cin >> q;
  while (q--){
    int x1, y1, x2, y2;
    cin >> r1 >> c1 >> r2 >> c2;
    cout << pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1] << '\n';
  }
  return 0;
}
