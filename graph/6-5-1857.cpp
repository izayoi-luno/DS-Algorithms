// leetcode #1857. 有向图中最大颜色值
// 有向图拓扑排序
// 拓扑排序 + 动态规划

/*
核心：
在拓扑排序数组中加一个颜色维度 每个颜色对应一个小写字母 这样topo数组也是一个dp数组
枚举新的后继结点的时候进行状态转移 对每个颜色进行状态转移
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <map>
#include <numeric>

using namespace std;

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        // 邻接表
        vector<vector<int>> g(n);
        // 节点的入度统计，用于找出拓扑排序中最开始的节点
        vector<int> indeg(n);
        for (auto&& edge: edges) {
            ++indeg[edge[1]];
            g[edge[0]].push_back(edge[1]);
        }
        
        // 记录拓扑排序过程中遇到的节点个数
        // 如果最终 found 的值不为 n，说明图中存在环
        int found = 0;
        vector<vector<int>> f(n, vector<int>(26, 0));
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (!indeg[i]) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            ++found;
            int u = q.front();
            q.pop();
            // 将节点 u 对应的颜色增加 1
            ++f[u][colors[u] - 'a'];
            // 枚举 u 的后继节点 v
            for (int v: g[u]) {
                --indeg[v];
                // 状态转移：将 f(v,c) 更新为其与 f(u,c) 的较大值
                for (int c = 0; c < 26; ++c) {
                    f[v][c] = max(f[v][c], f[u][c]);
                }
                if (!indeg[v]) {
                    q.push(v);
                }
            }
        }

        if (found != n) {
            return -1;
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, *max_element(f[i].begin(), f[i].end()));
            /*
            max_element(f[i].begin(), f[i].end()) 返回一个迭代器，指向 f[i] 容器中最大元素的位置。
            *max_element(f[i].begin(), f[i].end()) 解引用这个迭代器，得到 f[i] 容器中的最大元素。
            */
        }
        return ans;
    }
};