#include<bits/stdc++.h>
using namespace std;

//source : Luv(Youtube channel name : Luv)
//use this when a is very big in (a^b)%mod or the base case
//time complexity log2 (b)
long long int powA(long long int a, long long int b, long long int mod) {
    long long int ans=1;
    while (b) {
        if (b&1) ans= (ans*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return ans%mod ;
}

int main(){
  //function details 
  //powA -> use it when a is bigger than int range in (a^b)%m
  return 0;
}
