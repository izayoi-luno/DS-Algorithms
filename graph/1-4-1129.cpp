// leetcode #1129. 颜色交替的最短路径
// 单源最短路径
// 1. bfs遍历

/*
由于没有权值 就使用bfs遍历
使用 0 表示红色，111 表示蓝色，对于某一节点 x，从节点 0 到节点 x 的红色边和蓝色边交替出现的路径有两种类型：
类型 0：路径最终到节点 x 的有向边为红色；
类型 1：路径最终到节点 x 的有向边为蓝色。
如果存在从节点 0 到节点 x 的类型 000 的颜色交替路径，并且从节点 x 到节点 y 的有向边为蓝色，那么该路径加上该有向边组成了从节点 0 到节点 y 的类型 1 的颜色交替路径。
类似地，如果存在从节点 0 到节点 x 的类型 1 的颜色交替路径，并且从节点 x 到节点 y 的有向边为红色，那么该路径加上该有向边组成了从节点 0 到节点 y 的类型 0 的颜色交替路径。
使用广度优先搜索获取从节点 0 到某一节点的两种类型的颜色交替最短路径的长度，广度优先搜索的队列元素由节点编号和节点路径类型组成，
初始时节点 0 到节点 0 的两种类型的颜色交替最短路径的长度都是 0，将两个初始值入队。
对于某一个队列元素，节点编号为 x，节点路径类型为 t，那么根据类型 t 选择颜色为 1−t 的相邻有向边，
如果有向边的终点节点 y 对应类型 1-t 没有被访问过，那么更新节点 y 的类型 1−t 的颜色交替最短路径的长度为节点 x 的类型 t 的颜色交替最短路径的长度加 1，并且将它入队。
从节点 0 到某一节点的颜色交替最短路径的长度为两种类型的颜色交替最短路径长度的最小值。
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
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<vector<int>>> next(2, vector<vector<int>>(n));
        for (auto &e : redEdges) {
            next[0][e[0]].push_back(e[1]);
        }
        for (auto &e : blueEdges) {
            next[1][e[0]].push_back(e[1]);
        }

        vector<vector<int>> dist(2, vector<int>(n, INT_MAX)); // 两种类型的颜色最短路径的长度
        queue<pair<int, int>> q;
        dist[0][0] = 0;
        dist[1][0] = 0;
        q.push({0, 0});
        q.push({0, 1});
        while (!q.empty()) {
            auto [x, t] = q.front();
            q.pop();
            for (auto y : next[1 - t][x]) {
                if (dist[1 - t][y] != INT_MAX) {
                    continue;
                }
                dist[1 - t][y] = dist[t][x] + 1;
                q.push({y, 1 - t});
            }
        }
        vector<int> answer(n);
        for (int i = 0; i < n; i++) {
            answer[i] = min(dist[0][i], dist[1][i]);
            if (answer[i] == INT_MAX) {
                answer[i] = -1;
            }
        }
        return answer;
    }
};