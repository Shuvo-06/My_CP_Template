#include<bits/stdc++.h>
using namespace std;

vector< pair<int,int> > moves;
void hanoi(int n,int st,int en){
  if (n==1) {
    moves.push_back({st,en});
    return ;
  }
  hanoi( n-1 , st , 6-st-en );
  moves.push_back({st,en});
  hanoi( n-1 , 6-st-en , en);
  return; 
}

int main() {
  //concept : Reducible ( https://youtu.be/rf6uf3jNjbo?si=ziH-CAAJMew3Ihnx )
  // time complexity - O(2^n-1)
  int n;
  cin>>n;
  
  //function hanoi(number of disks, starting rod number, ending rod number)
  hanoi(n,1,3);
  
  //output is stored in a vector of pair of size (2^n-1) named moves
  for (int i = 0; i < (1LL << n)-1; i++){
    cout<<moves[i].first<<" "<<moves[i].second <<endl;
  }
  
  return 0;
} 
