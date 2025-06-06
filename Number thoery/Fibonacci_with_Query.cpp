#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1000000007;

// iterative version
// logN per query
// can't support heavy querying, eg query count >= 1e7 for dp or other stuffs
long long int fib(long long int n, long long int a, long long int b) {
    if (n == 0) return a;
    for (long long int i = 63 - __builtin_clzll(n); i >= 0; i--) {
        long long int d = (a * ((2 * b - a + MOD) % MOD)) % MOD;
        long long int e = (a * a + b * b) % MOD;
        if ((n >> i) & 1) {
            a = e;
            b = (d + e) % MOD;
        } 
        else {
            a = d;
            b = e;
        }
    }
    return a;
}

int main(){
	// function descriptio : fib(element number - 1, first element in series, second element in series)
	// Time complexity : O(logn)
	// tested on CSES fibonacci number
	
	int q;
	cin >> q;
	while (q--){
		long long int x;
	  	cin >> x;
	  	cout << fib(x, 1, 1) << "\n";
	}
	return 0;
}
