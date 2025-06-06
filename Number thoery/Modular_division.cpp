#include <bits/stdc++.h>
using namespace std;

// p is prime 
// Time complexity : O(n)
// generated inv[i] = 1 / i (mod p)
vector <int> inv;
void init_inv(int n, int p) {
    inv.resize(n + 1);
    inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        inv[i] = (1LL * (p - p / i) * inv[p % i]) % p;
    }
}

long long int powA(long long int a, long long int b, long long int mod) {
    long long int ans=1;
    while (b) {
        if (b&1) ans= (ans*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return ans%mod ;
}
long long mod_div(long long P, long long Q, int mod) {
    return (P * powA(Q, mod - 2, mod)) % mod;
}


int main() {
  //use this to calculate P/Q mod mod
  //time complexity -> log2 (1e9) [approximately 30]
  //tested on codeforecs 2008F <https://codeforces.com/contest/2008/problem/F>
  
  cout << mod_div(85, 10, 1e9+7) << "\n";
  cout << mod_div(36, 6, 1e9+7) << "\n";
  return 0;
}
