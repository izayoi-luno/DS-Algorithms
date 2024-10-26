// leetcode #377 组合总和 Ⅳ
// 经典dp - 完全背包问题

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> dp(target + 1);

        dp[0] = 1;
        for(int i = 1; i <= target; i++) {
            for(int j = 0; j < nums.size(); j++) {
                if (i - nums[j] >= 0) {
                    if (dp[i] > LLONG_MAX - dp[i - nums[j]]) {
                        dp[i] = LLONG_MAX;
                        // 处理溢出情况
                    } else {
                        dp[i] += dp[i - nums[j]];
                    }
                }
            }
        }

        if (dp[target] > INT_MAX) {
            return 0;
            // 处理溢出情况
        }

        return static_cast<int>(dp[target]);
        }
};