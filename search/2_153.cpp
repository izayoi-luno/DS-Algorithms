// leetcode #153. 寻找旋转排序数组中的最小值
// 旋转数组 + 二分查找

/*
旋转数组的特性：
左半边的所有值大于右半边的所有值，所以：
当nums[mid] < nums[r]时，mid一定在右半边（没有旋转过的有序数组可以看成只有右半边）
当nums[mid] >= nums[r]时，mid一定在左半边
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] < nums[r]) r = mid;  // 注意由于循环条件是l < r所以这里让r等于mid而不是mid - 1
            else l = mid + 1;
        }
        return nums[l];
    }
};