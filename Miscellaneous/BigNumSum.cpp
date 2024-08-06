#include<bits/stdc++.h>
using namespace std ;

string BigNumSum(string n1,string n2) {
    int i = n1.size()-1, j = n2.size()-1, carry = 0;
    string sum="";
    while (i+j+2) {
        int a=0, b=0;
        if (i!=-1) {
            a = n1[i] - '0';
            i--;
        }
        if (j!=-1) {
            b = n2[j] - '0';
            j--;
        }
        sum.push_back( (a+b+carry)%10 + '0');
        carry = (a+b+carry)/10;
    }
    if (carry) sum.push_back(carry + '0');
    reverse(sum.begin(),sum.end());
    return sum;
}

int main(){
    //Function to sum integers (sum cannot be contained in any container)
    //Time complexity -> O(max(|a|, |b|) )
    //input type -> 2 string of int characters
    //output type -> a string
    while (true){
        string a,b;
        cin >> a >> b;
        cout << BigNumSum(a, b) <<"\n";
    }
    return 0;
}