// leetcode #540. 有序数组中的单一元素
// 二分查找 不变量问题

/*
对于下标 x 左边的下标 y，如果 nums[y]=nums[y+1]，则 y 一定是偶数，应该在右边找；
对于下标 x 右边的下标 z，如果 nums[z]=nums[z+1]，则 z 一定是奇数，应该在左边找。
反之亦然
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1])) l = mid + 1;
            else r = mid - 1; 
        }
        return nums[l];
    }
};