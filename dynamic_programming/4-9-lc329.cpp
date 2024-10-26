// leetcode #329 矩阵中的最长递增路径
// 经典二维dp - 记忆化搜索 深度优先搜索

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static constexpr int dir[4][2] = {{-1, 0},{1, 0}, {0, -1}, {0, 1}};
    int m, n;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        if(m == 0 || n == 0) return 0;

        vector<vector<int>> memo(m, vector<int>(n)); // memo数组记录从matrix[row][col]出发的最长路径
        int maxv = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                maxv = max(maxv, dfs(matrix, i, j, memo));
            }
        }

        return maxv;
    }

    int dfs(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& memo) {
        if(memo[row][col] != 0) return memo[row][col];
        memo[row][col]++;
        for(int i = 0; i < 4; i++) {
            int newRow = row + dir[i][0], newCol = col + dir[i][1];
            if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && matrix[newRow][newCol] > matrix[row][col]){
                memo[row][col] = max(memo[row][col], dfs(matrix, newRow, newCol, memo) + 1);
            }
        }
        return memo[row][col];
    }
};
