// leetcode #1277 统计全为 1 的正方形子矩阵
// 二维dp - 前缀和

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int len = min(m, n);
        int l, i, j;
        vector<vector<vector<int>>> mat(len + 1, vector<vector<int>>(m, vector<int>(n))); // dp[l, i, j] l是正方形大小 ij是代表以matrix[i, j]为左上角的正方形

        int ans = 0;
        for(int l = 1; l <= len; l++) {
            for(int i = 0; i + l <= m; i++) {
                for(int j = 0; j + l <= n; j++) {
                    if(l == 1) mat[l][i][j] = matrix[i][j];
                    else mat[l][i][j] = matrix[i][j] && mat[l - 1][i + 1][j] && mat[l - 1][i][j + 1] && mat[l - 1][i + 1][j + 1];
                    ans += mat[l][i][j];
                }
            }
        }

        return ans;
    }
};