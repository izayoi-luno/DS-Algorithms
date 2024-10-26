// leetcode #841. 钥匙和房间
// 有向图的弱连通性
// 1. dfs遍历

/*
判断有向图是否连通 或者转化为有向图的连通分量是否为1
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n, 0);
        int components = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(rooms, visited, i);
                components++;
            }
        }
        if(components == 1) return true;
        return false;
    }

    void dfs(vector<vector<int>>& rooms, vector<int>& visited, int i) {
        visited[i] = 1;
        for(int j : rooms[i]) {
            if(!visited[j]) dfs(rooms, visited, j);
        }
    }
};