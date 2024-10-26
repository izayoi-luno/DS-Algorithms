// leetcode #934. 最短的桥
// 无向图 - 可达性问题 - 最短的通路
// 1. bfs

/*
bfs注意点：
由于bfs的内存开销比较大 一般考虑在bfs的过程中改变图本身来记录visited而不是单独用一个数组来保存visited状态
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
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        vector<pair<int, int>> island;
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    q.emplace(i, j);
                    grid[i][j] = -1;
                    // 第一次bfs搜到第一个岛的所有节点并记录到island数组中 用-1表示已经搜索到
                    while(!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        island.emplace_back(x, y);
                        for(int k = 0; k < 4; k++) {
                            int nx = x + dirs[k][0];
                            int ny = y + dirs[k][1];
                            if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                                q.emplace(nx, ny);
                                grid[nx][ny] = -1;
                            }
                        }
                    }
                    // 第二次bfs考虑从第一个岛的所有节点开始bfs 遇到第一个1就返回step数量
                    for(auto &&[x, y] : island) {
                        q.emplace(x, y);
                    }
                    int step = 0;
                    while(!q.empty()) {
                        int s = q.size();
                        for(int i = 0; i < s; i++) {
                            auto [x, y] = q.front();
                            q.pop();
                            for(int k = 0; k < 4; k++) {
                                int nx = x + dirs[k][0];
                                int ny = y + dirs[k][1];
                                if(nx >= 0 && nx < n && ny >= 0 && ny < n) {
                                    // 遇到0才压入队列（即遇到0才bfs向外围走一步，避免内部节点重复搜索）
                                    if(grid[nx][ny] == 0) {
                                        q.emplace(nx, ny);
                                        grid[nx][ny] = -1;
                                    }
                                    else if(grid[nx][ny] == 1) return step;
                                }
                            }
                        }
                        step++; // 步数在这里++：当岛屿最外围一圈所有节点都向外bfs一圈之后才将步数加1
                    }
                }
            }
        }
        return 0;
    }
};