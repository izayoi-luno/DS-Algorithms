// leetcode #740 删除并获得点数
// 一维dp - 状态转移 - 把问题转化为打家劫舍问题

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int maxv = 0;
        for(int i = 0; i < n; i++) {
            maxv = max(maxv, nums[i]);
        }

        vector<int> sum(maxv + 1); // 把问题nums转化为打家劫舍问题的nums
        for(int val : nums) {
            sum[val] += val;
        }

        return rob(sum);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];

        for(int i = 1; i < n; i++) {
            if(i == 1) dp[1] = max(nums[0], nums[1]);
            else dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[n - 1];
    }
};