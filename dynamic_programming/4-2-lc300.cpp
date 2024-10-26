// leetcode #300 最长递增子序列
// 最长递增子序列

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n); // dp[i]代表nums的[0, i]区间中的最长递增子序列的长度

        int maxv = 0;
        for(int i = 0; i < n; i++) {
            dp[i] = 1;
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    if(dp[j] + 1 > dp[i]) dp[i] = dp[j] + 1; // 选择某个最长状态进行转移
                }
            }
            maxv = max(maxv, dp[i]);
        }

        return maxv;
    }
};