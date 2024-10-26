// leetcode #11. 盛最多水的容器
// 贪心 + 双指针

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
贪心思想是：为了找到递增的三元子序列，first 和 second 应该尽可能地小，此时找到递增的三元子序列的可能性更大。
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        int first = nums[0], second = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            if (num > second) return true;
            else if (num > first) second = num;
            else first = num;
        }
        return false;
    }
};