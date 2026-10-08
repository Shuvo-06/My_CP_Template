#include <bits/stdc++.h>
using namespace std;

struct cmp {
    bool operator()(pair<int,int> a, pair<int,int> b) const {
        if (a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
  
    return 0;
}
