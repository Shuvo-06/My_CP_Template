#include <bits/stdc++.h>
using namespace std;
 
#define int long long int
// works for any associative operations (AND, OR, SUM, GCD, min, max)
// O(1) amortized for push, pop, and aggregate query

struct OrQueue {
    stack<pair<int, int>> in_stack, out_stack;

    void push(int x) {
        int new_or = in_stack.empty() ? x : (in_stack.top().second | x);
        in_stack.push({x, new_or});
    }

    void pop() {
        if (out_stack.empty()) {
            while (!in_stack.empty()) {
                int x = in_stack.top().first;
                in_stack.pop();
                int new_or = out_stack.empty() ? x : (out_stack.top().second | x);
                out_stack.push({x, new_or});
            }
        }
        if (!out_stack.empty())
            out_stack.pop();
    }

    int get_or() {
        int or1 = in_stack.empty() ? 0 : in_stack.top().second;
        int or2 = out_stack.empty() ? 0 : out_stack.top().second;
        return or1 | or2;
    }
};

struct AndQueue {
    stack<pair<int, int>> in_stack, out_stack;

    void push(int x) {
        int new_and = in_stack.empty() ? x : (in_stack.top().second & x);
        in_stack.push({x, new_and});
    }

    void pop() {
        if (out_stack.empty()) {
            while (!in_stack.empty()) {
                int x = in_stack.top().first;
                in_stack.pop();
                int new_and = out_stack.empty() ? x : (out_stack.top().second & x);
                out_stack.push({x, new_and});
            }
        }
        if (!out_stack.empty())
            out_stack.pop();
    }

    int get_and() {
        int and1 = in_stack.empty() ? ~0 : in_stack.top().second; // ~0 = all bits 1
        int and2 = out_stack.empty() ? ~0 : out_stack.top().second;
        return and1 & and2;
    }
};


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    #ifdef SUBLIME
        freopen("inputf.in", "r", stdin);
        freopen("outputf.out", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif

    int n, k;
    cin >> n >> k;
    vector <int> v(n);
    for (auto &x : v) cin >> x;

    int ans = 0;
    OrQueue q;

    for (int i = 0; i < n; ++i) {
        q.push(v[i]);
        if (i >= k - 1) {
            ans ^= q.get_or();
            q.pop();
        }
    }

    cout << ans << "\n";
    return 0;
}
