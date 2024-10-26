// leetcode #90. 子集 II
// 回溯法

/*
这道题注意要避免重复组合
这道回溯的特点：
没有一个明确的递归目标来记录和退出
而是每次遍历就记录 配合重复避免
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
#include <set>

using namespace std;

class Solution {
public:
    vector<int> visited;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        visited.resize(nums.size());
        backtrack(nums, ans, subset, 0);
        return ans;
    }

    void backtrack(vector<int>& nums, vector<vector<int>>& ans, vector<int>& subset, int idx) {
        ans.push_back(subset);
        for (int i = idx; i < nums.size(); i++) {
            // 去掉重复的
            if (visited[i] || i > idx && nums[i] == nums[i - 1] && !visited[i - 1]) continue;
            subset.push_back(nums[i]);
            visited[i] = 1;
            backtrack(nums, ans, subset, i + 1);
            visited[i] = 0;
            subset.pop_back();
        }
    }
};