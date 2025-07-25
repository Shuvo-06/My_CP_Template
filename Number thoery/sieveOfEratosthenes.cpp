#include <bits/stdc++.h>
using namespace std;

vector<bool> isPrime;
vector<int> primes;
constexpr bool init_sieve(int n,bool genArr){
    isPrime.resize(n, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2;  i*i < n; i++){
        if (isPrime[i]){
            for (int j = i*i; j < n; j+=i) isPrime[j] = false;
        }
    }
    if (genArr){
      for (int i=2; i<n;i++) {
        if (isPrime[i]) primes.push_back(i);
      }
    }
    return true;
}

int main(){
    //Sieve of Eratosthenes
    //Time complexity -> O(nloglogn) ( approximately O(n) )
    //used to precalculate if a number is Prime or not in a given range 
    //use true if you want a array of primes, otherwise use false
    //function description -> sieve (range, if you want an array of primes or not)

    init_sieve(1e6+7, true);
    
    int tt;
    cin >> tt;
    while (tt--){
        int n;
        cin >> n;
        cout << ((isPrime[n]) ? ("YES") : ("NO")) <<"\n";
    }
    return 0;
}
