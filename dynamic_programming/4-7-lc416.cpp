// leetcode #416 分割等和子集
// 经典二维dp - 0-1背包问题

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return false; // 数组太小 不可能找到

        int sum = 0, maxNum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            maxNum = max(maxNum, nums[i]);
        }
        if(sum & 1) return false; // 和为奇数 不可能找到
        if(maxNum > sum / 2) return false; // 最大值大于一半 则其余所有数都小于一半 不可能找到

        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1)); // dp数组dp[i][j]表示数组的[0, i]元素中 能否找到一个选择方式使得选择的元素之和等于J

        /* 处理边界情况 */
        for(int i = 0; i < n; i++) dp[i][0] = true; // 和为0 一定存在 选择0个
        dp[0][nums[0]] = true; // 第0个数 只能选择nums[0]

        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= target; j++) {
                if(j >= nums[i]) dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i]]; // 目标比当前大 可以选可以不选 只要有一个是true就返回true
                else dp[i][j] = dp[i - 1][j]; // 目标比当前小 必不能选
            }
        }

        return dp[n - 1][target];
    }
};