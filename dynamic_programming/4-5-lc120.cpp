// leetcode #120 三角形最小路径和
// 矩阵 - 二维dp

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m));

        dp[0][0] = triangle[0][0];
        for(int i = 1 ; i < m; i++) {
            for(int j = 0; j <= i; j++) {
                if(j == 0) dp[i][j] = dp[i - 1][j] + triangle[i][j];
                else if(j == i) dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                else dp[i][j] = triangle[i][j] + min(dp[i - 1][j - 1], dp[i - 1][j]); 
            }
        }
        
        int minv = INT_MAX;
        for(int i = 0; i < m; i++) {
            minv = min(minv, dp[m - 1][i]);
        }

        return minv;
    }
};