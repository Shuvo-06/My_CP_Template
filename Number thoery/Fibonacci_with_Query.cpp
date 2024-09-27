#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1000000007;

map <long long int, long long int> F;
long long int fib(long long int n) {
	if (n < 0) return -1;
	if (F.count(n)) return F[n];
	
	long long int k = (n >> 1);
	if ((n & 1) == 0) return F[n] = (fib(k) * fib(k) + fib(k-1) * fib(k-1)) % MOD;
	else return F[n] = (fib(k) * fib(k+1) + fib(k-1) * fib(k)) % MOD;
}

int main(){
	F[0] = 1;
	F[1] = 1;
	// for fibonacci series : 1 1 2 3 5 8 13 21 34 55
	// indexing like vector and other DS
	// can calculate upto 1e18
	// Time complexity : O(logn * loglogn)
	
	int q;
	cin >> q;
	while (q--){
	  long long int x;
	  cin >> x;
	  cout << fib(x) << "\n";
	}
	return 0;
}
