// leetcode #797. 所有可能的路径
// 有向图路径数量
// 1. dfs遍历 -> 回溯

/*
核心：在递归的过程中记录路径
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
    vector<vector<int>> res;
    vector<int> route;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph, 0);
        return res;
    }

    void dfs(vector<vector<int>>& graph, int cur) {
        route.push_back(cur);
        if(cur == graph.size() - 1) {
            res.push_back(route);
            route.pop_back();
            return;
        }
        for(int next : graph[cur]) {
            dfs(graph, next);
        }
        route.pop_back();
    }
};