#include <bits/stdc++.h>
using namespace std;

// Time complexity : O(n * m) 


string BigNumMul(string &num1, string &num2) {
    if(num1 == "0" || num2 == "0") return "0";

    int n = num1.size(), m = num2.size();
    vector<int> result(n + m, 0);

    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0'), sum = mul + result[i + j + 1];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    string ans = "";

    for(int val : result) {
        if(!(ans.empty() && val == 0)) ans += (val + '0');
    }

    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    #ifdef SUBLIME
        freopen("inputf.in", "r", stdin);
        freopen("outputf.out", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif
    
    string a, b;
    cin >> a >> b;

    cout << BigNumMul(a, b) << endl;
    return 0;
}
