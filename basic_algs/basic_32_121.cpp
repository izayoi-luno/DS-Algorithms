//leetcode #121 买卖股票的最佳时机
// 2D动态规划问题

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len < 2) return 0;

        vector<vector<int>> dp; // 二维数组 行数是天数 列数是持股状态 0=未持股 1=持股
        dp.resize(len, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for(int i = 1; i < len; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]); // 今天没持股的最优值是昨天也没持股和今天卖出的最大值
            dp[i][1] = max(dp[i - 1][1], -prices[i]); // 今天持股的最优值是昨天也持股和今天买入的最大值
        }
        return dp[len - 1][0];
    }
};