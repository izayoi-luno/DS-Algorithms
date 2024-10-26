//leetcode #704 二分查找
// solution-1 迭代法-分割数组
// solution-2 递归法-分割数组

#include <iostream>
#include <vector>

using namespace std;

class Solution_1 {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        // 注意迭代条件
        while(start <= end) {
            int mid = (start + end) / 2;
            if(target < nums[mid]) end = mid - 1;
            else if(target > nums[mid]) start = mid + 1;
            else return mid;
        }
        return -1;
    }
};

class Solution_2 {
public:
    int search(vector<int>& nums, int target) {
        return searchNum(nums, 0, nums.size() - 1, target);
    }
    int searchNum(vector<int>& nums, int start, int end, int target) {
        int mid = (start + end) / 2;
        // 注意递归条件
        if(start <= end) {
            if(target > nums[mid]) return searchNum(nums, mid + 1, end, target);
            else if(target < nums[mid]) return searchNum(nums, start, mid - 1, target);
            else return mid;
        }
        return -1;
    }
};