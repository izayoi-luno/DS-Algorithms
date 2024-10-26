//leetcode #53 最大子序和
// 动态规划自底向上

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0]; // 初始化最初的最大值
        int result = dp[0]; // 保存最大值
        for(int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]); // 比较前面的数组之和与当前输入大小 目的是看到底应该新开一个数组还是保持原数组继续累加
            if(dp[i] > result) result = dp[i];
        }
        return result;
    }
};