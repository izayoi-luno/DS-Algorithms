// leetcode #714 买卖股票的最佳时机含冷冻期
// 经典二维dp

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(n));

        if(n < 2) return 0;

        dp[0][0] = 0;
        dp[1][0] = - prices[0];
        dp[0][1] = max(dp[0][0], dp[1][0] + prices[1]);
        dp[1][1] = max(- prices[1], dp[1][0]);
 
        for(int i = 2; i < n; i++) {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + prices[i]);
            dp[1][i] = max(dp[0][i - 2] - prices[i], dp[1][i - 1]); // 注意状态转移dp[0][i - 1]是不可能转移到dp[1][i]的
            /*
            如果dp[1][i]要从dp[0][i - 1]转移 那么必然dp[0][i - 1]是没有卖出的 
            也就是说dp[0][i - 1]等于dp[0][i - 2]而不是dp[0][i - 1] + prices[i] 
            这样和直接从dp[0][i - 2]转移等价
            */
        }

        return dp[0][n - 1];
    }
};
