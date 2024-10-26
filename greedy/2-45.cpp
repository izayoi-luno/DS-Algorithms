// leetcode #45. 跳跃游戏 II
// 标准贪心

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 贪心版本
class Solution {
public:
    int jump(vector<int>& nums) {
        int maxPos = 0, n = nums.size(), end = 0, step = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (maxPos >= i) {
                maxPos = max(maxPos, i + nums[i]);
                if (i == end) {
                    end = maxPos;
                    ++step;
                }
            }
        }
        return step;
    }
};

// 动态规划版本 - O(n^2)
class Solution2 {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (j + nums[j] >= i) dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        return dp[n - 1];
    }
};