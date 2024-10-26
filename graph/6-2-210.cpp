// leetcode #210. 课程表 II
// 有向图拓扑排序
// 拓扑排序

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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
        if (sorti.size() == numCourses) return sorti;
        return {};
    }
};