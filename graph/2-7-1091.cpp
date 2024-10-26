// leetcode #1091. 二进制矩阵中的最短路径
// 无向图 - 最短距离
// 1. bfs

/*
核心：用空间换时间
这里计步数/距离的时候 原本应该用大循环保证向外搜索一圈之后再step++
但是这样会超时 所以改用一个step数组来记录每个点已走过的距离 顺便当visited数组用

距离问题的注意点：
1. 要么大循环计数一次再自增距离
2. 要么用多余的step数组保存每个节点离开始节点的距离
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
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1;
        vector<vector<int>> dirs = {{1, 0}, {1, 1}, {1, -1}, {0, 1}, {0, -1}, {-1, 0}, {-1, 1}, {-1, -1}};
        queue<tuple<int, int>> q;
        q.emplace(0, 0);
        vector<vector<int>> step(n, vector<int>(n, INT_MAX));
        step[0][0] = 1;
        while(!q.empty()) {
            int s = q.size();
            auto [x, y] = q.front();
            q.pop();
            if(x == n - 1 && y == n - 1) return step[x][y];
            grid[x][y] = -1;
            for(int k = 0; k < 8; k++) {
                int nx = x + dirs[k][0];
                int ny = y + dirs[k][1];
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0 && step[nx][ny] == INT_MAX) {
                    q.emplace(nx, ny);
                    step[nx][ny] = step[x][y] + 1;
                }
            } 
        }
        return -1;
    }
};