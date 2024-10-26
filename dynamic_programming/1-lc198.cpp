// leetcode #198 打家劫舍
// 一维dp - 状态转移

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(110);
        dp[0] = nums[0];
        int n = nums.size();
        
        for(int i = 1; i < n; i++) {
            if(i == 1) dp[1] = max(nums[0], nums[1]);
            else dp[i] = max(dp[i-1], dp[i-2] + nums[i]); // dp不要去管每一个episode的过程 只管从前一状态递推过来 --- 贝尔曼方程
        }
        return dp[n-1];
    }
};