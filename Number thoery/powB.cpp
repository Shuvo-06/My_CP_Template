#include <bits/stdc++.h>
using namespace std;

long long int powB(long long int a, long long int b, long long int mod){
    long long int ans = 1%mod ;
    while (b){
        if ((b&1)==1) ans= (ans*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return ans;
}


int main(){
    // this functions are used to calculate (a ^ b ^ c) % mod using  ETF and Euler's theorem
    //use this function when power cannot be stored in any container and is in exponetial form
    //time complexity -> O(log2 b)
    //function calling -> powA(base, power % ETF, mod)

    int tt;
    cin >> tt;
    while (tt--){
        long long int a, b, c;
        cin >> a >> b >> c;
        cout << powB (a, powB(b, c, 1e9+6) , 1e9+7) <<"\n";
    }


    //4 ways to calculate ETF
    //from prime factorization -> product of base^power - base^(power-1)
    //from using formula -> n* product(1-1/prime_factor)
    //if mod is prime, than ETF(mod) = mod-1
    //using for loop to find co-primes in range [1,n-1] ( gcd(n,i)==1 )

    return 0;
}