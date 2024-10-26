// leetcode #864. 获取所有钥匙的最短路径
// 无向图 - 通路的距离
// 1. bfs

/*
核心：用位运算保存拿到的钥匙状态 以简化时空计算复杂度 防止超时超空间
bfs压队列和距离数组都要保存钥匙状态 这样才能在走回头路的同时不过度遍历 
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
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int keyNums = 0;
        int sx = 0;
        int sy = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] <= 'z' && grid[i][j] >= 'a') keyNums++;
                if(grid[i][j] == '@') {
                    sx = i;
                    sy = j;
                }
            }
        }
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<vector<int>>> step(m, vector<vector<int>>(n, vector<int>(1 << 6, -1)));
        queue<tuple<int, int, int>> q;

        int mask = 0;
        q.emplace(sx, sy, mask);
        step[sx][sy][mask] = 0;
        while(!q.empty()) {
            auto [x, y, mask] = q.front();
            q.pop();
            if(mask == (1 << keyNums) - 1) return step[x][y][mask];
            for(int i = 0; i < 4; i++) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] != '#' && step[nx][ny][mask] == -1) {
                    if(grid[nx][ny] == '.' || grid[nx][ny] == '@') {
                        q.emplace(nx, ny, mask);
                        step[nx][ny][mask] = step[x][y][mask] + 1;
                    }
                    if(grid[nx][ny] >= 'A' && grid[nx][ny] <= 'Z') {
                        if(mask & (1 << (grid[nx][ny] - 'A'))) {
                            q.emplace(nx, ny, mask);
                            step[nx][ny][mask] = step[x][y][mask] + 1;
                        }
                    }
                    if(grid[nx][ny] >= 'a' && grid[nx][ny] <= 'z') {
                        int nmask = mask | (1 << (grid[nx][ny] - 'a'));
                        q.emplace(nx, ny, nmask);
                        step[nx][ny][nmask] = step[x][y][mask] + 1;
                    }
                }
            }
        }
        return -1;
    }
}; 