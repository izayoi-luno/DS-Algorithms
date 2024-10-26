// leetcode #324. 摆动排序 II
// 贪心 + 排序

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        int x = (n + 1) / 2;  // 数组中相同元素的数目最多不超过 ⌊(n+1)/2⌋
        for (int i = 0, j = x - 1, k = n - 1; i < n; i += 2, --j, --k) {
            nums[i] = arr[j];
            if (i + 1 < n) {
                nums[i + 1] = arr[k];
            }
        }
    }
};