// leetcode #200. 岛屿数量
// 矩阵形态的无向图 - 连通分量个数
// 1. dfs遍历

/*
注意dfs的遍历方向
矩阵形态的图可以不用建立点边集/邻接矩阵/邻接表 直接走上下左右的格子就行
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
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    dfs(grid, visited, i, j);
                    res++;
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int i, int j) {
        visited[i][j] = 1;
        if(i < grid.size() - 1) {
            if(!visited[i + 1][j] && grid[i + 1][j] == '1') dfs(grid, visited, i + 1, j);
        } 
        if(i > 0) {
            if(!visited[i - 1][j] && grid[i - 1][j] == '1') dfs(grid, visited, i - 1, j);
        } 
        if(j < grid[0].size() - 1) {
            if(!visited[i][j + 1] && grid[i][j + 1] == '1') dfs(grid, visited, i, j + 1);
        }
        if(j > 0) {
            if(!visited[i][j - 1] && grid[i][j - 1] == '1') dfs(grid, visited, i, j - 1);
        } 
    }
};