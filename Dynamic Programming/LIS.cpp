#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    cin >> n;
    vector <int> v(n), lis;
    for (auto &x : v) cin >> x;
 
    lis.push_back(v[0]);
    for (auto x : v) {
        if (x > lis.back()) lis.push_back(x);
        else lis[lower_bound(lis.begin(), lis.end(), x) - lis.begin()] = x;
    }
    cout << lis.size() << "\n";
    return 0;
