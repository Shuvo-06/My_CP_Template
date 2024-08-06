#include <bits/stdc++.h>
using namespace std;

void Csort1(vector<int> &v){
    vector<int> hash( *max_element(v.begin(),v.end())+1,0);
    for (int i=0; i<v.size(); i++) hash[v[i]]++;
    int ind =0;
    for (int i=0; i<hash.size(); i++) {
        for (int j=0; j<hash[i]; j++,ind++) v[ind] = i;
    }
    return ;
}

void Csort2(vector<int> &v){
    int maximum= *max_element(v.begin(),v.end()) ;
    int minimum= *min_element(v.begin(),v.end()) ;
    vector<int> hash( maximum - minimum + 1 , 0);
    for (int i=0; i<v.size(); i++) hash[v[i]-minimum]++;
    int ind = 0;
    for (int i=0; i<hash.size(); i++) {
        for (int j=0; j<hash[i]; j++,ind++) v[ind] = i+minimum;
    }
    return ;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin>>v[i];
    
    Csort1(v);
    for (int i=0; i<n; i++) cout<<v[i]<<" ";
    //counting sort version 1 -> Csort1
    //O(max)
    //only applicable for v[i]>=0
    //suitable for lower max value
    
    //Csort2(v);
    //for (int i=0; i<n; i++) cout<<v[i]<<" ";
    //counting sort version 2 -> Csort2
    //works for all integers
    //O(max-min+1)
    //suitable for lower max-min+1

    return 0;
}