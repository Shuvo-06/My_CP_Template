#include <bits/stdc++.h>
using namespace std;

vector <bool> isPrime;
vector <int> spf;
void SPF(int n){
  isPrime.resize(n + 1, false);
  spf.resize(n + 1, -1);
	for (int i = 2; i <= n; i += 2)	spf[i] = 2;
	for (int i = 3; i <= n; i += 2){
		if (!isPrime[i]){
			spf[i] = i;
			for (int j = i; j * i <= n; j += 2){
				if (!isPrime[j * i]){
				  isPrime[j * i] = true;
				  spf[j * i] = i;
				}
			}
		}
	}
	return;
}

vector <int> factorize(int k) {
	vector <int> ans;
	while(k > 1) {
		ans.push_back(spf[k]);
		k /= spf[k];
	}
	return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  // Size of spf array can be at most 1e7 
  // Smallest Prime factor (SPF) 
  // Time complexity : O(nloglogn) but lower operation count than usual
  // Super fast factorization
  // Time complexity O(logN)
  return 0;
}
