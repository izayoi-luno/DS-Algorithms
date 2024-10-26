// leetcode #1466. 重新规划路线
// 有向图、有向树的可达性
// 1. dfs遍历

/*
如果忽略边的方向变成无向图 那么所有节点都能到达0节点 现在就要看每条边到底要走哪条边 
如果从某个节点到0节点走原边那么就不用反向 否则就反向

构造与无向图等价的有向图：为条边添加反边 并标记每条边是原边还是反边
从0节点开始dfs遍历 记录走正边的次数就是答案
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
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> e(n);
        for(auto edge : connections) {
            e[edge[0]].push_back(make_pair(edge[1], 1));
            e[edge[1]].push_back(make_pair(edge[0], 0));
        }
        return dfs(0, -1, e);
    }

    int dfs(int x, int parent, vector<vector<pair<int, int>>>& e) {
        int res = 0;
        for(auto &edge : e[x]) {
            if(edge.first == parent) continue; // 如果走的边是反向边就不计入
            res += edge.second + dfs(edge.first, x, e);
        }
        return res;
    }
};