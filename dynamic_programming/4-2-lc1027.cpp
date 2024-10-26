// leetcode #1027 最长等差数列
// 最长递增子序列

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int res = 0;
        for(int i = -500; i <= 500; i++) {
            res = max(res, longestArithSeq(nums, i));
        }
        return res;
    }

    int longestArithSeq(vector<int>& nums, int diff) {
        int n = nums.size();
        vector<int> dp(1001, 0); // dp[i]代表 以nums中的每个值为结束 所能构成的最长等差数列的长度
        int val = 0;
        int maxv = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] - diff < 0) val = 0; // 因为 0 <= nums[i] <= 500
            else val = dp[nums[i] - diff];
            /* 由于同一个值可能在nums中出现多次 对应多种可能的等差子序列 取最长的那一种子序列*/
            if(val + 1 > dp[nums[i]]) {
                dp[nums[i]] = val + 1;
                maxv = max(maxv, dp[nums[i]]);
            }
        }

        return maxv;
    }
};