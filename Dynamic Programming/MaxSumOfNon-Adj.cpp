#include <bits/stdc++.h>
using namespace std;

// Maximum sum of non-adjacent elements
// Time complexity - O(n)

long long int calc(vector <long long int> &nums){
    vector <int> dp(nums.size(), 0);
    dp[0] = nums[0]; //dp[0] = max(0, nums[0]);
    dp[1] = max(dp[0], nums[1]); //dp[1] = max({0, nums[1], dp[0]});
 
    for (int i = 1; i < (int)dp.size(); i++) dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    return dp.back();
}

int main() {
    ll n;
    cin >> n;
    vector <int> nums(n);
    for (auto &x : nums) cin >> x;
    cout << calc() << "\n";
}
