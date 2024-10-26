// leetcode #1376. 通知所有员工所需的时间
// 带权有向树的遍历
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
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> g;
        for(int i = 0; i < n; i++) {
            g[manager[i]].emplace_back(i); // 核心：建立一个从 manager[i] 到 i 的有向图的邻接表
        }
        return dfs(headID, manager, informTime, g);
    }

    int dfs(int mng, vector<int>& manager, vector<int>& informTime, unordered_map<int, vector<int>>& g) {
        int res = 0;
        for(int child : g[mng]) res = max(res, dfs(child, manager, informTime, g)); // 比较每个child的长度 取最长的
        return informTime[mng] + res;
        }
};