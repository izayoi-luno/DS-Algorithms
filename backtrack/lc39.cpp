// leetcode #39. 组合总和
// 回溯法

/*
这道题注意要避免重复组合
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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        backtrack(candidates, ans, comb, target, 0);
        return ans;
    }

    void backtrack(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& comb, int target, int idx) {
        if (target == 0) {
            ans.push_back(comb);
            return;
        }
        for (int i = idx; i < candidates.size(); i++) {
            if (target - candidates[i] >= 0) {
                comb.push_back(candidates[i]);
                backtrack(candidates, ans, comb, target - candidates[i], i);
                comb.pop_back();
            }
        }
    }
};