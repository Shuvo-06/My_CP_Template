#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1000000007;

/*
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
*/

const long long int MOD = 1e9 + 7;
 
map <long long int, pair <long long int, long long int> > fib_memo;
pair <long long int, long long int> fib_internal (long long int n) {
    if (fib_memo.count(n)) return fib_memo[n];
 
    auto [ft1, ft2] = fib_internal(n >> 1);
    long long int c = (ft1 * ((2 * ft2) % MOD - ft1 + MOD) % MOD) % MOD;
    long long int d = ((ft1 * ft1) % MOD + (ft2 * ft2) % MOD) % MOD;
    
    if (n & 1) return fib_memo[n] = {d, (c + d) % MOD};
    else return fib_memo[n] = {c, d};
}
long long int fib(long long int n) {return fib_internal(n).first;}
 
int32_t main() {
    fib_memo[0] = {0, 1}; // first and second element
	// time complexity : O(logn * loglogn) 
	// allows heavy querying due to memoization
    
    long long int n;
    cin >> n;
    cout << fib(n);
}
