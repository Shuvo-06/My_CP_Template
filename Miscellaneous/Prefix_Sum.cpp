#include <bits/stdc++.h>
using namespace std;

int main(){
    //Prefix Sum technique
    //Static Range query
    //Time complexity -> O(n+q)
    //Used to know the sum of a subarray of range [l,r] 

    int n;
    cin >> n ;
    vector<int> pref(n+1,0) ;
    for (int i=1; i<=n; i++) {
        int k;
        cin >> k;
        pref[i] = pref[i-1] + k ;
    }

    int qq;
    cin >> qq;
    while (qq--){
        int l,r ; //1-indexed;
        cin >> l >> r;
        cout << pref[r] -pref[l-1] << "\n";
    }
    return 0;
}