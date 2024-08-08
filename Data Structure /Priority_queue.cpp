#include <bits/stdc++.h>
using namespace std;

int main() {
  //declartion
  priority_queue<int> pq;
  
  //declaration using custom comparator
  //priority_queue<int, cmp func> cmpq;
  
  //insertion
  pq.push(5);
  pq.emplace(10);
  
  //maximum element
  cout << pq.top() << "\n";
  
  //acessing size of priority queue
  cout << pq.size() << "\n";
  
  //boolean of emptiness of priority queue
  cout << pq.empty() << "\n";
  
  //deletion of maximum element
  pq.pop();
  
  return 0;
}
