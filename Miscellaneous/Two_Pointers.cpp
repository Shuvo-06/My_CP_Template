#include <bits/stdc++.h>
using namespace std;

int main(){
  //2sum using two pointers technique
  //Time complexity -> O(n)
  //Pre-requisite -> sorted array
  //tested on CSES "sum of two values problem"

  
  int n,x;
  cin >> n >> x;
  vector<pair<int, int>> v(n);
  for (int i=0; i<n; i++){
    cin>>v[i].first;
    v[i].second = i + 1;
  }
  sort(v.begin(), v.end());
  
  int l = 0, r = n-1;
  while (l < r){ //if duplicate index can be taken ,use l<=r
    if (v[l].first + v[r].first == x) {
      cout << v[l].second << " " << v[r].second <<"\n";
      return 0;
    }
    else if (v[l].first + v[r].first > x ) r--;
    else l++;
  }
  cout << "IMPOSSIBLE" << "\n";
  return 0;
}
