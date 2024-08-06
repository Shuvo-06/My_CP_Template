#include <bits/stdc++.h>
using namespace std;

int bsearch(vector<int> &v, int t) {
    int l = 0, r = v.size()-1;
    while (l <= r) {
        int mid = l+(r-l)/2;
        if (v[mid] == t) return mid;
        if (v[mid] > t) r = mid -1;
        else l = mid+1;
    }
    return -1;
}

int bsearch2(vector<int> &v, int t) {
    int k = 0;
    for (int b = v.size()/2; b >= 1; b /= 2) {
        while (k+b < v.size() && v[k+b] <= t) k += b;
    }
    if (v[k] == t) return k;
    else return -1;
}

int main() {
    //Binary search
    //Searches element in a unique sorted array
    //Time complexity -> log2(n)
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin>>v[i];
   
    int qq;
    cin>>qq;
    while (qq--){ 
        int q;
        cin>>q;
        cout<< bsearch2(v,q) <<"\n";
    }

    return 0;
}