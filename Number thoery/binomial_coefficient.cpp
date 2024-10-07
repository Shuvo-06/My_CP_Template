#include <bits/stdc++.h>
using namespace std;

vector<long long int> fact, inv_fact;
long long int powA(long long int a, long long int b, long long int mod = 1000000007) {
  long long int ans = 1;
  while (b) {
    if (b&1) ans= (ans*a) % mod;
    a = (a*a) % mod;
    b >>= 1;
  }
  return ans % mod ;
}
void pre_fact(long long int n = 200000, long long int mod = 1000000007) {
  fact.resize(n + 1);
  inv_fact.resize(n + 1);
  fact[0] = 1;
  for (long long int i = 1; i <= n; ++i) fact[i] = (fact[i - 1] * i) % mod;
  inv_fact[n] = powA(fact[n], mod - 2, mod);
  for (long long int i = n - 1; i >= 0; --i) {
    inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod;
  }
  return;
}
long long int nCr(long long int n, long long int r, long long int mod = 1000000007) {
  if (r > n) return 0;
  return fact[n] * inv_fact[r] % mod * inv_fact[n - r] % mod;
}
long long int nPr(long long int n, long long int r, long long int mod = 1000000007) {
  if (r > n) return 0;
  return fact[n] * inv_fact[n - r] % mod;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // Time complexity -> O(n + q)
  // binary exponentiation is triggered every MAXN times while pre query with O(30) constant time 
  
  // Pre computation part
  pre_fact(200000, 1000000007);
  
  int qq;
  cin >> qq;
  while (qq--){
    long long int n, r;
    cin >> n >> r;
    cout << nCr(n, r) << " " << nPr(n, r) << "\n";
  }
  return 0;
}
