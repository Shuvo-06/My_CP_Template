#include<bits/stdc++.h>
using namespace std;

//subsidiary function of powM
//time complexity log2 (b)  (added in powM time complexity)
long long int binMul(long long int a, long long int b, long long int mod) {
    long long int ans=0;
    while (b) {
        if (b&1) ans=(ans+a)%mod;
        a = (a+a)%mod;
        b >>= 1;
    }
    return ans%mod ;
}

long long int powM(long long int a, long long int b, long long int mod) {
    long long int ans=1;
    while (b) {
        if (b&1) ans= binMul(ans,a,mod);
        a = binMul(a,a,mod);
        b >>= 1;
    }
    return ans%mod ;
}

int main(){
  //source : Luv(Youtube channel name : Luv)
  //use this when mod is very big in (a^b)%mod 
  //time complexity ( log2(b) )^2
  return 0;
}
