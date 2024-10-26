// leetcode #540. 有序数组中的单一元素
// 二分查找 不变量问题

/*
注意不要数组越界
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n - 1, ans = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (arr[mid] > arr[mid + 1]) {
                r = mid - 1;
                ans = mid;
            }
            else l = mid + 1;
        }
        return ans;
    }
};
