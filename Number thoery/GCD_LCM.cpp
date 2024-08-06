#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if (a==0) return b;
    return gcd(b%a,a);
}

int lcm(int a,int b){
    return (a*b) / gcd(a,b);
}

int main(){
    //GCD using euclidean method
    //There is a built-in method to calculate GCD in bits/stdc++.h, In case, you cannot use that,you can use this function
    //time complexity -> O(log min(a,b))
    //worst case scenario -> two consecutive fibonacci numbers

    int tt ;
    cin>>tt ;
    while (tt--){
        int a,b;
        cin>>a>>b;
        cout<< gcd(a,b) << lcm(a,b) <<"\n";
    }
    return 0;
}