// leetcode #154. 寻找旋转排序数组中的最小值 II
// 旋转数组 + 二分查找

/*
有重复元素
大于和小于是一样的处理方式
等于的处理方式:
由于重复元素的存在，不能确定 nums[mid] 究竟在最小值的左侧还是右侧，因此不能忽略左半边或者右半边。
由于它们的值相同，所以无论 nums[r] 是不是最小值，都有一个它的「替代品」nums[mid]，因此我们可以忽略二分查找区间的右端点。
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
            if (nums[mid] < nums[r]) r = mid;
            else if (nums[mid] > nums[r]) l = mid + 1;
            else r -= 1;  // 核心语句
        }
        return nums[l];
    }
};