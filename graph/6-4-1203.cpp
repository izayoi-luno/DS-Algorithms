// leetcode #1203. 项目管理
// 有向图拓扑排序
// 拓扑排序

/*
核心：
最主要的难点在于处理未分组的项目 他有可能会与某些组的项目产生依赖或被依赖关系 从而导致一组的项目连不到一起
1. 给所有未分组的项目分配不同的组号
2. 分别建立组的邻接表 项目的邻接表 组的入度序列 项目的入度序列
3. 建立组到项目的一对多关系
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
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // 第 1 步：数据预处理，给没有归属于一个组的项目编上组号
        for (int i = 0; i < group.size(); i++) {
            if (group[i] == -1) group[i] = m++;
        }
        // 第 2 步：实例化组和项目的邻接表
        vector<vector<int>> groupAdj(m);
        vector<vector<int>> itemAdj(n);
        // 第 3 步：建图和统计入度数组
        vector<int> groupInGegree(m, 0);
        vector<int> itemInGegree(n, 0);
        for (int i = 0; i < n; i++) {
            int currGroup = group[i];
            for (int beforeItem : beforeItems[i]) {
                int beforeGroup = group[beforeItem];
                if (beforeGroup != currGroup) {
                    groupAdj[beforeGroup].push_back(currGroup);
                    groupInGegree[currGroup]++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int item : beforeItems[i]) {
                itemAdj[item].push_back(i);
                itemInGegree[i]++;
            }
        }
        // 第 4 步：得到组和项目的拓扑排序结果
        vector<int> groupList = topoSort(groupAdj, groupInGegree, m);
        if (groupList.size() == 0) return {};
        vector<int> itemList = topoSort(itemAdj, itemInGegree, n);
        if (itemList.size() == 0) return {};
        // 第 5 步：根据项目的拓扑排序结果，项目到组的多对一关系，建立组到项目的一对多关系
        // key：组，value：在同一组的项目列表
        map<int, vector<int>> groupToItem;
        for (int item : itemList) {
            groupToItem[group[item]].push_back(item);
        }
        // 第 6 步：把组的拓扑排序结果替换成为项目的拓扑排序结果
        vector<int> res;
        for (int groupId : groupList) {
            vector<int> items = groupToItem[groupId];
            for (int item : items) res.push_back(item);
        }
        return res;
    }

    vector<int> topoSort(vector<vector<int>>& adj, vector<int>& inDegree, int n) {
        vector<int> res;
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for (int next : adj[node]) {
                inDegree[next]--;
                if (inDegree[next] == 0) q.push(next);
            }
        }
        if(res.size() == n) return res;
        return {};
    }
};