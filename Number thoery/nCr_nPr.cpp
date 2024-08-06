#include <iostream>
using namespace std;

long long int nCr(long long int n,long long int r){
    if (n < r) return -1;
    if (n==1) return 1;
    if (r==0) return 0;
    long long int up=1, down=1;
    for (long long int i=1,j=n; j>n-r; j--,i++){
        up *= j;
        down *= i;
    }
    return up/down;
}

long long int nCr2(long long int n, long long int r){
    if (n < r) return -1;
    if (r == 1 || n == r + 1) return n;
    if (r == 0) return 0;
    if (n == r) return 1;
    return nCr2(n - 1, r - 1) + nCr2(n - 1, r);
}

long long int nPr(long long int n, long long int r){
    if (n < r) return -1;
    long long int ans = 1;
    for (long long int i=n-r+1 ; i<=n; i++) ans*=i;
    return ans;
}

int main(){
    //nCr represents the number of ways to take r elements from a total of n elements where the order of these element doesn't matter
    //1 2 3 and 2 1 3 is considered as same
    //using iteration time complexity O(n-r)
    //using recursion time complexity O(2^n)

    //nPr represents the number of ways to take r elements from a total of n elements where the order of these element  matters
    //1 2 3 and 2 1 3 would be counted differently
    //using iteration time complexity O(r)

    //function description
    // function -> nCr or nPr or nCr2 (total elements, elemets to chose)
    //returns -1, if such arrangement is impossible

    cout << nCr(7, 5) <<"\n";
    cout << nCr2(6, 5) <<"\n";
    cout << nPr(4, 1) <<"\n";

    return 0;
}