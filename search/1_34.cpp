// leetcode #34. 在排序数组中查找元素的第一个和最后一个位置
// 二分查找

/*
找两个下标
*/

#include <iostream>
#include <vector>

using namespace std;

// 标准二分查找
class Solution1 { 
public:
    int binarySearch(vector<int>& nums, int target, bool lower) {
        int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target)) {
                right = mid - 1;
                ans = mid;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int leftIdx = binarySearch(nums, target, true);
        int rightIdx = binarySearch(nums, target, false) - 1;
        if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target) {
            return vector<int>{leftIdx, rightIdx};
        } 
        return vector<int>{-1, -1};
    }
};

// 利用lb和ub函数的方法
class Solution2 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return {-1, -1};
        vector<int> ans(2);
        if (nums.back() < target) return {-1, -1};
        else if (nums.back() == target) {
            ans[1] = n - 1;
            auto l = lower_bound(nums.begin(), nums.end(), target);
            ans[0] = distance(nums.begin(), l);
        }
        else {
            auto lb = lower_bound(nums.begin(), nums.end(), target);
            auto ub = upper_bound(nums.begin(), nums.end(), target);
            int l = distance(nums.begin(), lb);
            int r = distance(nums.begin(), ub);
            ans[0] = (nums[l] == target ? l : -1);
            ans[1] = (nums[l] == target ? r - 1 : -1);
        } 
        return ans;
    }
};