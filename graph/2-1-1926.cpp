// leetcode #1926. 迷宫中离入口最近的出口
// 无向图 - 可达性问题 - 最短的通路
// 1. bfs

/*
bfs核心：
用队列保存与当前节点连接的一圈节点
以出发节点开始遍历与本节点相邻的节点并依次压入队列中
遍历完成后从队列头部弹出节点进入下一个状态
核心：依次以队首弹出的顺序遍历
直到遍历到目标退出

形象化：以开始节点一圈一圈地探索
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
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        queue<tuple<int, int, int>> q;
        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, 1, 0, -1};

        q.emplace(entrance[0], entrance[1], 0);
        maze[entrance[0]][entrance[1]] = '+';
        while(!q.empty()) {
            auto [cur_x, cur_y, d] = q.front();
            q.pop();
            for(int k = 0; k < 4; k++) {
                int new_x = cur_x + dx[k];
                int new_y = cur_y + dy[k];
                if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && maze[new_x][new_y] == '.') {
                    if(new_x == 0 || new_x == m - 1 || new_y == 0 || new_y == n - 1) return d + 1;
                    maze[new_x][new_y] = '+';
                    q.emplace(new_x, new_y, d + 1);
                }
            }
        }

        return -1;
    }
};