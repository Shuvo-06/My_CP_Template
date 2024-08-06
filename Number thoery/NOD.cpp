#include <bits/stdc++.h>
using namespace std;

void sieveNOD(vector<int> &nod){
    for (int i=2; i<nod.size(); i++){
        nod[i]+=2;
        for (int j=i*i; j<nod.size(); j+=i) {
            if (j==i*i) nod[j] ++;
            else nod[j] += 2;
        }
    }
    nod[0] = 0;
    nod[1] = 1;
    return ;
}

int main(){
    vector<int> nod(1e6+7);
    sieveNOD(nod);

    //Number of divisors using sieve of Eratosthenes logic
    //time complexity -> O(nlogn)
    int x;
    cin >> x;
    for (int i=0; i<=x; i++) cout <<i<<" -> "<< nod[i] << "\n";
    return 0;
}