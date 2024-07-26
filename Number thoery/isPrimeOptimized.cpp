#include<bits/stdc++.h>
using namespace std;

bool isPrime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long int i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) return false;
  }
  return true;
}

//this is the traditional function
/*
bool isPrime2(long long int n){
  if (n<=1) return false;
  for (long long int i=2; i*i<=n; i++) if (n%i==0) return false;
  return true;
}
*/

int main(){
  //source : Arifin Ikram ,KUET 
  //time complexity O( √n )
  //Although, the time complexity is the same, the optimized code is 6 times faster than the traditional one
  long long int n;
  cin >> n;
  cout << isPrime(n) <<"\n";
  return 0;
}
