#include <bits/stdc++.h>
using namespace std;

void sieveSOD(vector<int> &sod){
    for (int i=2; i<sod.size(); i++){
        sod[i]+=i+1;
        for (int j=i*i; j<sod.size(); j+=i) {
            if (j==i*i) sod[j] += i;
            else sod[j] += (i+j/i);
        }
    }
    sod[0] = 0;
    sod[1] = 1;
    return ;
}


int main(){
    vector<int> sod(1e6+7,0);
    sieveSOD(sod);

    //Sum of divisors using sieve of Eratosthenes logic
    //time complexity -> O(nlogn)

    
    int x;
    cin >> x;
    for (int i=0; i<=x; i++) cout <<i<<" -> "<< sod[i] << "\n";
    return 0;
}