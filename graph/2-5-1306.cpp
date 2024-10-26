// leetcode #1306. 跳跃游戏 III
// 有向图 - 可达性问题
// 1. bfs

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> visited(n, 0);
        queue<int> q;
        q.emplace(start);
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            int next_1 = curr + arr[curr];
            int next_2 = curr - arr[curr];
            if(next_1 < n && !visited[next_1]) {
                if(arr[next_1] == 0) return true;
                q.emplace(next_1);
                visited[next_1] = 1;
            }
            if(next_2 >= 0 && !visited[next_2]) {
                if(arr[next_2] == 0) return true;
                q.emplace(next_2);
                visited[next_2] = 1;
            }
        }
        return false;
    }
};