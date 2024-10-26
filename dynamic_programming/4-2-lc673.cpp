// leetcode #673 最长递增子序列的个数
// 最长递增子序列

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        nums.push_back(INT_MAX); // 在最后项加一个最大值
        int n = nums.size();
        vector<int> dp(n);
        vector<int> count(n);

        for(int i = 0; i < n; i++) {
            dp[i] = count[i] = 1; // 注意初始化
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    if(dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }
                    else if(dp[j] + 1 == dp[i]) count[i] += count[j];
                }
            }
        }

        return count[n - 1];
    }
};