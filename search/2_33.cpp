// leetcode #33. 搜索旋转排序数组
// 旋转数组 + 二分查找

/*
基本思路：
区间 [l, mid] 和 [mid + 1, r] 有且只有一个是有序的
只在[0, mid], [mid + 1, n - 1]中有序的那部分中找
在有序的那部分中确定二分条件：
以[0, mid]为例，判断target是否大于nums[0]且小于nums[mid] 是则在[0, mid - 1]中找，不是则在非有序的那部分找
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (!n) return -1;
        if (n == 1) return nums[0] == target ? 0 : -1;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) r = mid - 1;
                else l = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) l = mid + 1;
                else r = mid - 1;
            }
        }
        return -1;
    }
};