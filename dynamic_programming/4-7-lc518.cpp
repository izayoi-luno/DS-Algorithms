// leetcode #518 零钱兑换 II
// 经典dp - 完全背包问题

/*
和 377 作对比：
遍历的顺序不同 这里外层遍历每个硬币 内层遍历每个目标值 保证每种排列不会重复计数
在 377 中 内外层遍历相反 就会计数每种不同的排列
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<long long> dp(amount + 1);

        dp[0] = 1;
        for(int c = 0; c < coins.size(); c++) {
            for(int i = coins[c]; i <= amount; i++) {
                dp[i] += dp[i - coins[c]];
            }
        }

        return dp[amount];
    }
};