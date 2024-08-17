#include <bits/stdc++.h>
using namespace std;

int main(){
  //2D Prefix Sum
  //Time complexity -> O(nm + q)
  
  int n,m;
  cin >> n >> m ;
  vector<vector<int>> pref(n+1, vector<int>(m+1,0));
  for (int i=1; i<=n; i++){
    for (int j=1; j<=m; j++){
      cin >> pref[i][j];
      pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] ;
    }
  }
  
  int q;
  cin >> q;
  while (q--){
    // (x1, y1) -> top left corner of the rectangle
    // (x2, y2) -> bottom right corner of the rectangle
    // 1-indexed
    int x1, y1, x2, y2; 
    cin >> x1 >> y1 >> x2 >> y2;
    cout << pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1] << "\n";
  }
  return 0;
}
