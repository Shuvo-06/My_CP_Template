#include<bits/stdc++.h>
using namespace std;

int main(){
    //deque -> double ended Queue
    //Declaration
    deque<int> d;

    //insertion and removal of elements --> O(1)
    //for insertion at back -> push_back or emplace_back
    //for insertion at front -> push_front or emplace_front
    d.push_back(5);
    d.push_front(10);
    d.pop_back();
    d.pop_front();

    d.push_back(10);
    d.push_front(20);
    d.push_back(30);
    d.push_front(15);


    //acessing elements -> O(1)
    cout << d.at(2) << '\n';
    cout << d.front() << '\n';
    cout << d.back() << '\n';

    //swapping
    deque<int> d2;
    d.swap(d2);

    //some useful functions of deque
    cout << d2.size() << '\n';
    cout << d2.max_size() << '\n';

    d.erase(d.begin());  //erase() -> deletes specific element
    d.clear();  //clear() -> deletes entire deque
  
    //empty() -> returns boolen
    if (d.empty()) cout << "Empty" << "\n";
    else cout << "Not empty" << '\n';

    //printing whole deque
    for (auto x : d2) cout << x << " ";
    cout << "\n";

    for (int i=0; i<d2.size(); i++) cout << d2.at(i) << " ";
    cout << "\n";

    for (auto it = d2.begin(); it != d2.end(); it++) cout << *it << " ";
    cout << "\n";
    
    return 0;
}
