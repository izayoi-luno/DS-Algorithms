// leetcode #78 子集
// 1. 递推：对原集合每一个元素考虑，每次迭代将每个元素与已生成幂集前面的元素（集合）做拼接
// 2. 回溯：对每一个长度进行考虑，然后对每个元素开头的可能性进行回溯

#include <iostream>
#include <vector>

using namespace std;

class Solution1 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back(vector<int>());
        int n = nums.size();

        for(int num : nums) {
            vector<vector<int>> helper;
            for(vector<int> i : res) {
                vector<int> copy = i;
                copy.push_back(num);
                helper.push_back(copy);
            }
            for(vector<int> i : helper) {
                res.push_back(i);
            }
        }

        return res;
    }
};

class Solution2 {
public:
    vector<vector<int>> res;
    int n, k;

    void backtrack(int first, vector<int>& helper, vector<int>& nums){
        // 递归退出条件 当回溯到符合预定长度的子集返回
        if(helper.size() == k) {
            res.push_back(helper);
            return;
        }

        for(int i = first; i < n; i++) {
            helper.push_back(nums[i]);
            backtrack(i + 1, helper, nums); // 防止元素重复 子集长度不够从下一个元素开始回溯
            helper.pop_back(); // 在不是最后一个结局方案之前进行回溯
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();

        // 对每一个子集长度进行考虑 k是长度
        for(k = 0; k <= n; k++) {
            vector<int> helper;
            backtrack(0, helper, nums); // 每次从nums的第零个元素作为开头开始考虑
        }

        return res;
    }
};