#include <bits/stdc++.h>
using namespace std;

// Next Smaller Element (Right)
vector<int> nextSmaller(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, n);
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] > arr[i]) {
            res[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    return res;
}

// Next Greater Element (Right)
vector<int> nextGreater(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, n);
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            res[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    return res;
}

// Previous Smaller Element (Left)
vector<int> prevSmaller(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> s;
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] > arr[i]) {
            res[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    return res;
}

// Previous Greater Element (Left)
vector<int> prevGreater(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> s;
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            res[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    return res;
}

int main() {
    
    return 0;
}
