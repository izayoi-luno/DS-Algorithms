// leetcode #63 不同路径 II
// 矩阵 - 二维dp

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m));

        if(obstacleGrid[n - 1][m - 1]) return 0; // 特殊情况 终点有障碍物

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 && j == 0) dp[i][j] = 1;
                else if(i == 0) {
                    if(!obstacleGrid[i][j - 1]) dp[i][j] = dp[i][j - 1];
                    else dp[i][j] = 0;
                }
                else if(j == 0) {
                    if(!obstacleGrid[i - 1][j]) dp[i][j] = dp[i - 1][j];
                    else dp[i][j] = 0;
                }
                else {
                    if(!obstacleGrid[i][j - 1] && obstacleGrid[i - 1][j]) dp[i][j] = dp[i][j - 1];
                    else if(obstacleGrid[i][j - 1] && !obstacleGrid[i - 1][j]) dp[i][j] = dp[i - 1][j];
                    else if(obstacleGrid[i][j - 1] && obstacleGrid[i - 1][j]) dp[i][j] = 0;
                    else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};