// leetcode #494. 目标和
// 回溯法 + 运算符问题

/*
这道题类似于lc679

本题用动态规划的效率会高一些
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

// 暴力搜索
class Solution1 {
public:
    int res;
    int sm;
    int findTargetSumWays(vector<int>& nums, int target) {
        sm = 0;
        backtrack(nums, target, 0);
        return res;
    }

    void backtrack(vector<int>& nums, int target, int idx) {
        if (idx == nums.size()) {
            if (sm == target) res++;
            return;
        }
        sm += nums[idx];
        backtrack(nums, target, idx + 1);
        sm -= nums[idx];

        sm -= nums[idx];
        backtrack(nums, target, idx + 1);
        sm += nums[idx];
    }
};