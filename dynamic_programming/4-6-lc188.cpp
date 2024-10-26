// leetcode #122 买卖股票的最佳时机 IV
// 经典多维dp - 多出来的一个维度就是买卖次数 对于不同的买卖次数做不同的转移处理

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(k, vector<int>(n))); // 将2次买卖推广到k维

        for(int i = 0; i < k; i++) {
            dp[0][i][0] = 0;
            dp[1][i][0] = - prices[0];
        }
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < k; j++) {
                dp[0][j][i] = max(dp[0][j][i - 1], dp[1][j][i - 1] + prices[i]);
                if(j == 0) dp[1][j][i] = max( - prices[i], dp[1][j][i - 1]);
                else dp[1][j][i] = max(dp[0][j - 1][i] - prices[i], dp[1][j][i - 1]);
            }
        }

        int maxv = 0;
        for(int i = 0; i < k; i++) {
            maxv = max(maxv, dp[0][i][n - 1]);
        }

        return maxv;
    }
};