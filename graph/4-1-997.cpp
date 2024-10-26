// leetcode #997. 找到小镇的法官
// 有向图 - 入度和出度
// 1. 直接建图 2. 入度出度分析

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 直接法：判断是否有且仅有一个法官 + 判断是否所有节点都直接指向法官
class Solution1 {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int m = trust.size();
        unordered_map<int, unordered_set<int>> adj;
        for(int i = 0; i < m; i++) {
            adj[trust[i][0]].insert(trust[i][1]);
        }
        vector<int> judge;
        for(int i = 1; i <= n; i++) {
            if(adj[i].empty()) judge.push_back(i);
        }
        if(judge.size() != 1) return -1;
        for(int i = 1; i <= n; i++) {
            if(i != judge[0]) {
                if(!adj[i].count(judge[0])) return -1;
            }
        }
        return judge[0];
    }
};

// 法官的入度是 n - 1 出度是0 并且是唯一的
class Solution2 {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDegrees(n + 1);
        vector<int> outDegrees(n + 1);
        for (auto& edge : trust) {
            int x = edge[0], y = edge[1];
            ++inDegrees[y];
            ++outDegrees[x];
        }
        for (int i = 1; i <= n; ++i) {
            if (inDegrees[i] == n - 1 && outDegrees[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};
