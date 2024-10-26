// leetcode #207. 课程表
// 有向图拓扑排序
// 拓扑排序

/*
拓扑排序核心：
从入度为0的节点开始排序 并从图中删除该节点 此时会改变图中其他节点的入度
当所有入度为0的节点删除后 会出现新的度数为0的节点 重复上述步骤直到所有的节点都排序

实现：
利用队列 先将入度为 0 的节点依次入队
从队首取节点加入最终排序数组 并遍历节点的邻接表 将邻接的节点的入度减一
当发现有邻接节点的度数减到 0 了就把这个邻接节点入队

直观理解：
游戏中点技能树的逻辑
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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDeg(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            inDeg[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        queue<int> q;
        vector<int> sorti;
        for(int i = 0; i < numCourses; i++) {
            if(inDeg[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            sorti.push_back(node);
            for (int next : adj[node]) {
                inDeg[next]--;
                if(inDeg[next] == 0) q.push(next);
            }
        }
        if (sorti.size() == numCourses) return true;
        return false;
    }
};