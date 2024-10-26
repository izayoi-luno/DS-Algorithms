// leetcode #2779. 数组的最大美丽值
// 排序 + 滑动窗口

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0, j = 0; i < n; i++) {
            while (nums[i] - 2 * k > nums[j]) {
                j++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};