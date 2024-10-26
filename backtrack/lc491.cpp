// leetcode #491. 非递减子序列
// 回溯法 + 子序列排列问题

/*
这道题类似于lc47

核心在于判断重复，并且和47不同的是，本题的原数组顺序不可变
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
    vector<vector<int>> ans;
    vector<int> seq;
    vector<int> visited;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        visited.resize(nums.size(), 0);
        backtrack(nums, 0);
        return ans;
    }

    void backtrack(vector<int>& nums, int idx) {
        if (seq.size() > 1) ans.push_back(seq);
        if (idx == nums.size()) return;
        for (int i = idx; i < nums.size(); i++) {
            // * 判断重复，注意范围是从当前的开始 index 到 i
            int vis = 0;
            for (int j = idx; j < i; j++) {
                if (nums[i] == nums[j] && !visited[j]) vis = 1;
            }
            if (visited[i] || vis) continue;
            if (seq.empty() || nums[i] >= seq.back()) {
                seq.push_back(nums[i]);
                visited[i] = 1;
                backtrack(nums, i + 1);
                visited[i] = 0;
                seq.pop_back();
            }
        }
    }
};