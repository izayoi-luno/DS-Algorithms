// leetcode #40. 组合总和 II
// 回溯法

/*
这道题注意要在避免重复组合的基础上避免重复组合 类似于lc47题 
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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        visited.resize(candidates.size());
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, ans, comb, target, 0);
        return ans;
    }

    void backtrack(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& comb, int target, int idx) {
        if (target == 0) {
            ans.push_back(comb);
            return;
        }
        for (int i = idx; i < candidates.size(); i++) {
            if (visited[i] || (i > 0 && candidates[i] == candidates[i - 1] && !visited[i - 1])) {
                continue;
            }
            if (target - candidates[i] >= 0) {
                comb.push_back(candidates[i]);
                visited[i] = 1;
                backtrack(candidates, ans, comb, target - candidates[i], i);
                comb.pop_back();
                visited[i] = 0;
            }
        }
    }
};