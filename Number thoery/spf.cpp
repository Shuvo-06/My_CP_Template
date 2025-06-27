#include <bits/stdc++.h>
using namespace std;

vector<bool> isPrime;
vector<int> spf;
void init_spf(int n) {
    isPrime.assign(n + 1, true);
    spf.assign(n + 1, -1);

    isPrime[0] = isPrime[1] = false;
    spf[0] = 0;
    spf[1] = 1;

    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            spf[i] = i;
            for (long long int j = 1LL * i * i; j <= n; j += i) {
                if (isPrime[j]) {
                    isPrime[j] = false;
                    spf[j] = i;
                }
            }
        }
    }
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
  // Time complexity O(√n / log n)
  return 0;
}
