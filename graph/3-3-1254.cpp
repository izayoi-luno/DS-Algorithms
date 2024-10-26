// leetcode #1254. 统计封闭岛屿的数目
// 矩阵形态的无向图 - 连通分量个数
// 1. dfs遍历

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int res = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && grid[i][j] == 0) {
                    if(i == 0 || i == m - 1 || j == 0 || j == n - 1) dfs(grid, visited, i, j);
                }

            }
        }

        for(int i = 1; i < m - 1; i++) {
            for(int j = 1; j < n - 1; j++) {
                if(!visited[i][j] && grid[i][j] == 0) {
                    dfs(grid, visited, i, j);
                    res ++;
                }

            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j) {
        visited[i][j] = 1;
        if(i < grid.size() - 1) {
            if(!visited[i + 1][j] && grid[i + 1][j] == 0) dfs(grid, visited, i + 1, j);
        } 
        if(i > 0) {
            if(!visited[i - 1][j] && grid[i - 1][j] == 0) dfs(grid, visited, i - 1, j);
        } 
        if(j < grid[0].size() - 1) {
            if(!visited[i][j + 1] && grid[i][j + 1] == 0) dfs(grid, visited, i, j + 1);
        }
        if(j > 0) {
            if(!visited[i][j - 1] && grid[i][j - 1] == 0) dfs(grid, visited, i, j - 1);
        } 
    }
};