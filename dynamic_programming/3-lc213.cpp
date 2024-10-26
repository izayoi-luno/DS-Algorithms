// leetcode #213 打家劫舍II
// 二维dp - 状态转移

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2)); // 用二维数组 第二维表示：0 = 第一家没打劫  1 = 第一家打劫了

        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        dp[0][0] = 0;
        dp[0][1] = nums[0];
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < 2; j++) {
                if(i == 1) {
                    if(j == 0) dp[i][j] = nums[1];
                    else dp[i][j] = nums[0];
                }
                else if(i == n - 1 && j == 1) dp[i][j] = dp[i-1][j];
                else dp[i][j] = max(dp[i-1][j], dp[i-2][j] + nums[i]);
            }
        }

        return max(dp[n-1][0], dp[n-1][1]);
    }
};