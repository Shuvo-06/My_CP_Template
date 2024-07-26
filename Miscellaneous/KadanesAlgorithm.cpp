#include <bits/stdc++.h>
using namespace std;

template<typename Iterator>
long long kadane(Iterator st_it, Iterator en_it) {
    using ValueType = typename iterator_traits<Iterator>::value_type;
    ValueType best = *st_it, sum = 0;
    for (Iterator it = st_it; it != en_it; ++it) {
        sum = max(*it, sum + *it);
        best = max(best, sum);
    }
    return best;
}

int main() {
    //Kadane's algorithm 
    //maximum subarray sum
    //Time complexity -> O(n)
    //function tested on CSES Maximum Subarray Sum problem
    //function description -> kadane (starting iterator, ending iterator) [like other STL functions v.begin(), v.end()]

    int n;
    cin >> n;
    vector<long long int> v(n);
    for (int i=0; i<n; i++) cin>>v[i];
    
    cout<< kadane(v.begin(), v.end()) <<"\n";
    
    return 0;
}
