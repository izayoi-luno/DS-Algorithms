// leetcode #221 最大正方形
// 二维dp - 二维前缀和

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        if(m == 0 || n == 0) return 0;

        vector<vector<int>> dp(m, vector<int>(n)); // dp[i][j]代表以matrix[i][j]为右下角的最大矩形的边长
        int maxv = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1') {
                    if(i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    }
                    maxv = max(maxv, dp[i][j]);
                }
            }
        }
        return maxv * maxv;
    }
};