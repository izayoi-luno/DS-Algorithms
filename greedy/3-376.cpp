// leetcode #376. 摆动序列
// 贪心

/*
贪心：不断地交错选择「峰」与「谷」，可以使得该序列尽可能长。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return n;
        }
        int prevDiff = nums[1] - nums[0];
        int ret = prevDiff != 0 ? 2 : 1;
        for (int i = 2; i < n; ++i) {
            int diff = nums[i] - nums[i - 1];
            if ((diff > 0 && prevDiff <= 0) || (diff < 0 && prevDiff >= 0)) {
                ++ret;
                prevDiff = diff;
            }
        }
        return ret;
    }
};