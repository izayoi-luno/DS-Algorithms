// leetcode #53 最大子数组和
// 经典dp

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n); // dp[i]表示nums的[0, i]区间内的最大子数组和

        dp[0] = nums[0];
        int res = nums[0];
        for(int i = 1; i < n; i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            res = max(res, dp[i]);
        }

        return res;
    }
};
