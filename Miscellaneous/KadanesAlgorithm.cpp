#include <bits/stdc++.h>
using namespace std;

long long int kadane_max(vector<long long int> &v, int sti, int eni) {
  long long int res = LLONG_MIN, curr = 0;
  for (int i = sti; i <= eni; i++) {
    curr = max(v[i], curr + v[i]);
    res = max(res, curr);
  }
  return res;
}

long long int kadane_min(vector<long long int> &v, int sti, int eni) {
  long long int res = LLONG_MAX, curr = 0;
  for (int i = sti; i <= eni; i++) {
    curr = min(v[i], curr + v[i]);
    res = min(res, curr);
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  // Kadane's Algorithm to find minimum and maximum sub-array sum
  // Time complexity : O(n)
  // Space complexity : O(n)
  // Tested on Codeforecs 2043C
  
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    
    if (n == 0) {
      cout << "No element\n";
      continue;
    }
    vector <long long int> v(n);
    for (auto &x : v) cin >> x;
    
    cout << kadane_min(v, 0, n -1) << " " << kadane_max(v, 0, n -1) << "\n";
  }
  return 0;
}
