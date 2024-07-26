#include <bits/stdc++.h>
using namespace std;

vector<bool> isPrime;
vector<int> primes;
void sieve(int n,bool genArr){
    isPrime.resize(n, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i=2;  i*i <isPrime.size(); i++){
        if (isPrime[i]){
            if (genArr) primes.push_back(i);
            for (int j=i*i; j < isPrime.size(); j+=i) isPrime[j] = false;
        }
    }
    return ;
}

int main(){
    //Sieve of Eratosthenes
    //Time complexity -> O(nloglogn) ( approximately O(n) )
    //used to precalculate if a number is Prime or not in a given range 
    //use true if you want a array of primes, otherwise use false
    //function description -> sieve (range, if you want an array of primes or not)

    sieve(1e6+7, true);
    
    int tt;
    cin >> tt;
    while (tt--){
        int n;
        cin >> n;
        cout << ((isPrime[n]) ? ("YES") : ("NO")) <<"\n";
    }
    return 0;
}
