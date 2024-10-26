// leetcode #695. 岛屿的最大面积
// 矩阵形态的无向图 - 节点数最多的连通分量的节点数
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
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int res = 0;
        int area = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && grid[i][j] == 1) {
                    dfs(grid, visited, i, j, area);
                    res = max(res, area);
                    area = 0;
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j, int& area) {
        visited[i][j] = 1;
        ++area;
        if(i < grid.size() - 1) {
            if(!visited[i + 1][j] && grid[i + 1][j] == 1) dfs(grid, visited, i + 1, j, area);
        } 
        if(i > 0) {
            if(!visited[i - 1][j] && grid[i - 1][j] == 1) dfs(grid, visited, i - 1, j, area);
        } 
        if(j < grid[0].size() - 1) {
            if(!visited[i][j + 1] && grid[i][j + 1] == 1) dfs(grid, visited, i, j + 1, area);
        }
        if(j > 0) {
            if(!visited[i][j - 1] && grid[i][j - 1] == 1) dfs(grid, visited, i, j - 1, area);
        } 
    }
};