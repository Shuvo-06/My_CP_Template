#include <bits/stdc++.h>
using namespace std;


int main() {
  //used to calculate 2D range update
  //time complexity -> O(n * m + q) 
  
  int n,m;
  cin >> n >> m;
  vector <vector<int>> vv(n, vector<int>(m,0));
  
  int q;
  cin >> q;
  while (q--){
    int r1,c1,r2,c2;
    cin >> r1 >> c1 >> r2 >> c2;
    vv[r1][c1]++;
    if (r2 + 1 < n && c2 + 1 < m) vv[r2 + 1][c2 + 1]++;
    if (r2 + 1 < n) vv[r2 + 1][c1]--;
    if (c2 + 1 < m) vv[r1][c2 + 1]--;
  }
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i > 0) vv[i][j] += vv[i - 1][j];
      if (j > 0) vv[i][j] += vv[i][j - 1];
      if (i > 0 && j > 0) vv[i][j] -= vv[i - 1][j - 1];
    }
  }
  
  for (auto x : vv){
    for (auto y : x){
      cout << y << " ";
    }
    cout << "\n";
  }
  return 0;
}
