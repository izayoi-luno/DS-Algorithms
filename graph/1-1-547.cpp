// leetcode #547. 省份数量
// 无向图连通分量
// 1. dfs遍历 2. 并查集

/*
1. dfs遍历思路：
对于邻接矩阵或者邻接表 访问每行（即访问每个节点） 看看这个节点和哪些节点相连 这些节点和本节点同属一个连通分量
用一个数组记录每个节点被访问与否 如果某个节点已被访问 说明已经记录到了一个连通分量 不必再重复计算
如果没被访问到 则可以进行dfs

核心：邻接矩阵和邻接表只保存直接相连的节点 要得到间接相邻的节点 则用dfs一层一层地搜
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution1 {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n);
        int provinces = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(isConnected, visited, n, i);
                provinces++;
            }
        }
        return provinces;
    }

    void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int n, int i) {
        for(int j = 0; j < n; j++) {
            if(isConnected[i][j] == 1 && !visited[j]) {
                visited[j] = 1;
                dfs(isConnected, visited, n, j); // dfs递归调用 实现深度搜索
            }
        }
    }

};