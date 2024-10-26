// leetcode #785. 判断二分图
// 无向二分图
// dfs + 三色标记法

/*
核心：
没经过的节点染黑色 = 0
经过的节点要么染红色 = 1；要么染蓝色 = 2
从第一个点开始dfs 先染红色
只需要让每走一步就染色一个节点
遇到没染色的就染上一个节点的不一样的颜色
遇到染色了的就判断是否应该是那个颜色 如果冲突就返回false
如果一直到最后都能不冲突地染色就返回true
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    bool valid;
    vector<int> color;
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        valid = true;
        color.assign(n, 0);
        for(int i = 0; i < n && valid; i++) {
            if(color[i] == 0) dfs(1, graph, i);
        }
        return valid;
    }

    void dfs(int c, const vector<vector<int>>& graph, int i) {
        color[i] = c;
        int cNew = (c == 1 ? 2 : 1);
        for(int next : graph[i]) {
            if(color[next] == 0) {
                dfs(cNew, graph, next);
                if(!valid) return;
            } 
            else if(color[next] != cNew) {
                valid = false;
                return;
            }
        }
    }
};