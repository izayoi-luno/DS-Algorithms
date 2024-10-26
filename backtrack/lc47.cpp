// leetcode #47. 全排列 II
// 回溯法

/*
要解决重复问题，我们只要设定一个规则，保证在填第 idx 个数的时候重复数字只会被填入一次即可。
而在本题解中，我们选择对原数组排序，保证相同的数字都相邻，
然后每次填入的数一定是这个数所在重复数集合中「从左往右第一个未被填过的数字」
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    vector<int> vis;  // visited数组 

public:
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, int idx, vector<int>& perm) {
        if (idx == nums.size()) {
            ans.emplace_back(perm);
            return;
        }
        for (int i = 0; i < (int)nums.size(); ++i) {
            // 前一个数必然先于这个数回溯到 如果前一个相同的数没有visited 说明之前已经回溯结束 现在再回溯会导致重复 
            // 所以一定要保证前面一个visited了 这说明本轮未重复的回溯还在进行中 
            if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {
                continue;
            }
            perm.emplace_back(nums[i]);
            vis[i] = 1;
            backtrack(nums, ans, idx + 1, perm);
            vis[i] = 0;
            perm.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> perm;
        vis.resize(nums.size());
        sort(nums.begin(), nums.end());
        backtrack(nums, ans, 0, perm);
        return ans;
    }
};