// leetcode #1615. 最大网络秩
// 无向图 - 度数
// 1. 建图 + 度数分析 2.枚举两个点是否连通 + 度数分析

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution1 {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, unordered_set<int>> adj;
        for(int i = 0; i < roads.size(); i++) {
            adj[roads[i][0]].insert(roads[i][1]);
            adj[roads[i][1]].insert(roads[i][0]);
        }
        int rank = 0;
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                int r = adj[i].size() + adj[j].size();
                if(adj[i].count(j)) rank = max(rank, r - 1);
                else rank = max(rank, r);
            }
        }
        return rank;
    }
};

class Solution2 {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<bool>> connect(n, vector<bool>(n, false));
        vector<int> deg(n);
        for(auto v : roads) {
            connect[v[0]][v[1]] = true;
            connect[v[1]][v[0]] = true;
            deg[v[0]]++;
            deg[v[1]]++;
        }

        int maxRank = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rank = deg[i] + deg[j] - (connect[i][j] ? 1 : 0);
                maxRank = max(maxRank, rank);
            }
        }
        return maxRank;
    }
};