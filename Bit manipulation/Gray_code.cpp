#include <bits/stdc++.h>
using namespace std;

// gray(i) = i ^ (i >> 1);
// rev_gray(gray(i)) = i

int gray (int n) {
  	return n ^ (n >> 1);
}
int rev_gray (int g) {
  	int n = 0;
  	for (; g; g >>= 1) n ^= g;
  	return n;
}

int main() {
  	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
  	// Gray Code 
    // The problem is to generate all the bit string of size n , where two adjacent bit string only differ by one bit (i.e Hamming distance is 1)
	// Time complexity : O(2 ^ n)
	// Gray code of n bits forms a Hamiltonian cycle on a hypercube, where each bit corresponds to one dimension.
	// Can be used to solve tower of hanoi problem
    // Tested on CSES : Gray Code problem

  	int n;
  	cin >> n;
  	for (int i = 0; i < (1<<n); i++){
    	for (int j = n-1; j >= 0; j--) cout << ((gray(i) >> j) & 1 );
    	cout << "\n";
  	}
  	return 0;
}
