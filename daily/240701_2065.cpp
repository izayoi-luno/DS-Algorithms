// leetcode #2065. 最大化一张图中的路径价值
// 无向带权图
// 建图 + 回溯型枚举

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int ans;
    vector<int> visited;
    vector<vector<pair<int, int>>> g;

    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        g.resize(n);
        for (const auto& edge: edges) {
            g[edge[0]].emplace_back(edge[1], edge[2]);
            g[edge[1]].emplace_back(edge[0], edge[2]);
        }

        visited.resize(n);
        visited[0] = true;
        ans = 0;
        
        dfs(0, 0, values[0], values, maxTime);
        return ans;
    }

    void dfs(int u, int time, int value, vector<int>& values, int maxTime) {
            if (u == 0) {
                ans = max(ans, value);
            }
            for (const auto& [v, dist]: g[u]) {
                if (time + dist <= maxTime) {
                    if (!visited[v]) {
                        visited[v] = true;
                        dfs(v, time + dist, value + values[v], values, maxTime);
                        visited[v] = false;
                    }
                    else {
                        dfs(v, time + dist, value, values, maxTime);
                    }
                }
            }
        };
};