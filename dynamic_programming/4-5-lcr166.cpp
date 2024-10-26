// leetcode #LCR 166 珠宝的最高价值
// 矩阵 - 二维dp

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jewelleryValue(vector<vector<int>>& frame) {
        int n = frame.size();
        int m = frame[0].size();
        vector<vector<int>> dp(n, vector<int>(m));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 && j == 0) dp[i][j] = frame[i][j];
                else if(i == 0) dp[i][j] = dp[i][j - 1] + frame[i][j];
                else if(j == 0) dp[i][j] = dp[i - 1][j] + frame[i][j];
                else dp[i][j] = frame[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n - 1][m - 1];
    }
};