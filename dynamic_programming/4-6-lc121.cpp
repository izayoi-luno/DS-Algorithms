// leetcode #121 买卖股票的最佳时机
// 经典二维dp

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(n, 0));

        dp[0][0] = 0;
        dp[1][0] = - prices[0];

        for(int i = 1; i < n; i++) {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + prices[i]);
            dp[1][i] = max( - prices[i], dp[1][i - 1]); // 这里是- prices[i]而不是dp[0][i - 1] - prices[i]的原因是只能买卖一次
        }

        return dp[0][n - 1];
    }
};