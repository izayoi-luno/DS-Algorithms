// leetcode #1557. 可以到达所有点的最少点数目
// 有向图 - 入度和出度
// 入度出度分析

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> inDegrees(n);
        vector<int> outDegrees(n);
        for(int i = 0; i < edges.size(); i++) {
            int from = edges[i][0], to = edges[i][1];
            inDegrees[to]++;
            outDegrees[from]++;
        }
        vector<int> res;
        for(int i = 0; i < n; i++) {
            if(inDegrees[i] == 0 && outDegrees[i] != 0) {
                res.push_back(i);
            }
        }
        return res;
    }
};