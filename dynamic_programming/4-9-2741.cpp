// leetcode #2741. 特别的排列
// 记忆化搜索 深度优先搜索 + 状态压缩

/*
状态压缩核心是利用位运算 用每个二进制位替代visited数组

因此设 dfs(state, i) 递归函数用于求解当前排列包含集合 state 表示的所有整数，并且最后一个整数为 nums[i] 时的特别排列数量。
其中 state 是状态压缩后的集合，其二进制表示中第 k 位为 1 则表示包含整数 nums[k]。

求解时：
dfs(state, i) = ∑ (j∈state) dfs(state⊕(1<<i), j)

其中，我们需要考虑 state 包含的所有 j，并且 i != j，且 nums[i] 可以作为 nums[j] 在特别排列中的后续相邻元素。
⊕ 表示异或操作，state⊕(1<<i) 用于去除 state 中的 nums[i]。

递归时，当遇到 state=(1<<i)，表示只包含一个元素，可直接返回 1。最后我们需要统计所有 dfs(state,i) 的和。
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static const int mod = 1e9 + 7;
    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(1 << n, vector<int>(n, -1));
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = (res + dfs((1 << n) - 1, i, dp, nums)) % mod;
        }        
        return res;
    }

    int dfs(int state, int i, vector<vector<int>>& dp, vector<int>& nums) {
        if (dp[state][i] != -1) {
                return dp[state][i];
        }
        if (state == (1 << i)) {
            return 1;
        }
        dp[state][i] = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (i == j || !(state >> j & 1)) {
                continue;
            }
            if (nums[i] % nums[j] != 0 && nums[j] % nums[i] != 0) {
                continue;
            }
            dp[state][i] = (dp[state][i] + dfs(state ^ (1 << i), j, dp, nums)) % mod;
        }
        return dp[state][i];
    }
};