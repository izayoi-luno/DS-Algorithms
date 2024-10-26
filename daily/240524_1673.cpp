// leetcode #1673 找出最具竞争力的子序列
// 单调栈 + 贪心

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;

        for(int i = 0; i < n; i++) {
            while(!res.empty() && res.size() + n - i > k && res.back() > nums[i]) res.pop_back(); // 使用单调栈将小的元素尽量放在栈底
            res.push_back(nums[i]);
        }

        res.resize(k); // 取前k个元素

        return res;
    }
};