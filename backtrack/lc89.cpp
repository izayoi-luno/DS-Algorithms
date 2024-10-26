// leetcode #89. 格雷编码
// 回溯法 + 位运算

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <map>
#include <numeric>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> ans;
    bool flag = false;
    int n;
    int limit;
    vector<int> grayCode(int n) {
        this->n = n;
        limit = (int)pow(2, n);
        vector<int> visited(limit);
        visited[0] = 1;
        ans.push_back(0);
        backtrack(0, visited);
        return ans;
    }

    void backtrack(int curr, vector<int>& visited) {
        if (ans.size() == limit) {
            if (__builtin_popcount(curr) == 1) flag = true;
            return;
        }
        for (int i = 0; i < n; i++) {
            int next = curr ^ (1 << i);  // 核心语句：位运算改变某一位的值
            if (!visited[next]) {
                visited[next] = 1;
                ans.push_back(next);
                backtrack(next, visited);
                if (flag) return;
                visited[next] = 0;
                ans.pop_back();
            }
        }
    }
};
