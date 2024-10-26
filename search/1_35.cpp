// leetcode #35. 搜索插入位置
// 二分查找

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1, ans = n;
        while (left <= right) {
            int mid = ((right - left) >> 1) + left;
            if (target <= nums[mid]) {
                ans = mid;  // 核心在此
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};