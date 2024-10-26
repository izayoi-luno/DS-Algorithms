// leetcode #322 零钱兑换
// 经典二维dp - 完全背包问题

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX - 1); // dp[i]代表组成面值为i所需要的最小硬币个数
        dp[0] = 0;
        /* 枚举每一种硬币和每一个面值 */
        for(int i = 0; i < coins.size(); i++) {
            for(int j = coins[i]; j <= amount; j++) {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1); // 滚动数组 将二维dp数组压缩成一维dp数组
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};