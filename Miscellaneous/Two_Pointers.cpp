#include <bits/stdc++.h>
using namespace std;

int main(){
    //2sum using two pointers technique
    //Time complexity -> O(n)
    //Pre-requisite -> sorted array
    
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin>>v[i];

    int tt;
    cin >> tt ;
    while (tt--){
        int x;
        cin >> x;
        int l=0, r=n-1 ;
        bool found = false;
        //if duplicate index can be taken,use l<=r
        while (l < r){
            if (v[l] + v[r] == x) {
                found = true;
                break;
            }
            else if (v[l] + v[r] > x ) r--;
            else l++;
        }

        if (found) cout << l << " " << r << "\n";
        else cout << -1 << "\n";
    }
    return 0;
}