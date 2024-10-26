// leetcode #417. 太平洋大西洋水流问题
// 矩阵形态的有向图 - 可达性问题
// 1. dfs遍历

/*
核心1：用两个visited状态数组代表可达性
核心2：从海洋边界反向dfs：为了减少遍历的次数以降低复杂度
向高处搜索 == 将有向图边的方向反向
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) dfs(i, 0, heights, pacific);
        for(int j = 1; j < n; j++) dfs(0, j, heights, pacific);
        for(int i = 0; i < m; i++) dfs(i, n - 1, heights, atlantic);
        for(int j = 0; j < n - 1; j++) dfs(m - 1, j, heights, atlantic);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    vector<int> cell;
                    cell.push_back(i);
                    cell.push_back(j);
                    res.push_back(cell);
                }
            }
        }

        return res;
    }

    void dfs(int row, int col, vector<vector<int>>& heights, vector<vector<int>>& ocean) {
        if(ocean[row][col]) return;
        ocean[row][col] = 1;

        int m = heights.size();
        int n = heights[0].size();
        if(row < m - 1 && heights[row][col] <= heights[row + 1][col]) dfs(row + 1, col, heights, ocean);
        if(row > 0 && heights[row][col] <= heights[row - 1][col]) dfs(row - 1, col, heights, ocean);
        if(col < n - 1 && heights[row][col] <= heights[row][col + 1]) dfs(row, col + 1, heights, ocean);
        if(col > 0 && heights[row][col] <= heights[row][col - 1]) dfs(row, col - 1, heights, ocean);
    }
};