// leetcode #1192. 查找集群内的关键连接
// 无向图连通分量/双连通分量的桥/割边
// 1. dfs遍历：Tarjan算法

/*
Tarjan提出的算法是用来找到无向图中的所有割边的经典算法。
Tarjan的算法基于深度优先搜索（DFS），并且使用了两个辅助数组：
1. disc[u]：表示顶点u被发现的时间戳。
2. low[u]：表示顶点u或其子树能够访问到的最早的祖先顶点的时间戳。
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
    vector<int> visited;
    vector<int> disc;
    vector<int> low;
    vector<vector<int>> bridges;
    int time;

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        visited.resize(n);
        disc.resize(n);
        low.resize(n);
        fill(visited.begin(), visited.end(), 0);
        fill(disc.begin(), disc.end(), -1);
        fill(low.begin(), low.end(), -1);
        time = 0;

        vector<vector<int>> adj(n, vector<int>());
        for(auto edge : connections) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for(int i = 0; i < n; i++) {
            if(!visited[i]) dfs(i, adj, -1);
        }

        return bridges;
    }

    void dfs(int u, vector<vector<int>>& adj, int parent) {
        visited[u] = 1;
        disc[u] = low[u] = ++time;

        for(int v : adj[u]) {
            if(!visited[v]) {
                dfs(v, adj, u);
                low[u] = min(low[u], low[v]);
                if(low[v] > disc[u]) bridges.push_back({u, v});
            }
            else if(v != parent) {
                low[u] = min(low[u], disc[v]);
            }
        }
    }
};