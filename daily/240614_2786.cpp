// leetcode #2786. 访问数组中的位置使分数最大
// 动态规划
// 二维dp - 滚动dp数组

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

// 超时的O(n2)方法
class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);

        dp[0] = nums[0];
        int maxn = nums[0];
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if((nums[i] % 2) == (nums[j] % 2)) dp[i] = max(dp[i], nums[i] + dp[j]);
                else dp[i] = max(dp[i], nums[i] + dp[j] - x);
            }
            maxn = max(maxn, dp[i]);
        }

        return maxn;
    }
};

// O(n)的方法
class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        int n = nums.size();
        vector<long long> dp(2, INT_MIN); // 滚动dp数组保存奇数和偶数元素的最大值

        dp[nums[0] % 2] = nums[0];
        long long maxn = nums[0];
        for(int i = 1; i < n; i++) {
            int parity = nums[i] % 2;
            long long cur = max(dp[parity] + nums[i], dp[1 - parity] + nums[i] - x); // 只从奇偶的最大值转移 避免遍历前i个元素
            maxn = max(maxn, cur);
            dp[parity] = max(dp[parity], cur);
        }

        return maxn;
    }
};