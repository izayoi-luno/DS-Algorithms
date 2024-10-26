// leetcode #122 买卖股票的最佳时机 III
// 经典多维dp - 多出来的一个维度就是买卖次数 对于不同的买卖次数做不同的转移处理

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(2, vector<int>(n))); // 三维数组[未持有/卖出=0 持有/买入=1][第一次交易=0 第二次交易=1][天数]

        dp[0][0][0] = 0;
        dp[1][0][0] = - prices[0];
        dp[0][1][0] = 0;
        dp[1][1][0] = - prices[0];
        
        for(int i = 1; i < n; i++) {
            dp[0][0][i] = max(dp[0][0][i - 1], dp[1][0][i - 1] + prices[i]);
            dp[1][0][i] = max( - prices[i], dp[1][0][i - 1]);

            dp[0][1][i] = max(dp[0][1][i - 1], dp[1][1][i - 1] + prices[i]); // 注意这里的转移 第二次交易未持有只能是 第一次卖过之后未持有 或者 第二次买过之后卖出
            dp[1][1][i] = max(dp[0][0][i] - prices[i], dp[1][1][i - 1]);
        }

        return max(dp[0][0][n - 1], dp[0][1][n - 1]);
    }
};