// leetcode #714 买卖股票的最佳时机含手续费
// 经典二维dp

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(n));

        dp[0][0] = 0;
        dp[1][0] = - prices[0];

        for(int i = 1; i < n; i++) {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + prices[i] - fee);
            dp[1][i] = max(dp[0][i - 1] - prices[i], dp[1][i - 1]); 
        }

        return dp[0][n - 1];
    }
};