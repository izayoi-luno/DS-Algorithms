// leetcode #55. 跳跃游戏
// 标准贪心

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int rightmost = 0;
        for (int i = 0; i < n; ++i) {
            // 保证第i位是能到达的
            if (i <= rightmost) {
                rightmost = max(rightmost, i + nums[i]);  // 只需要维护一个最远能到达距离
                if (rightmost >= n - 1) {
                    return true;
                }
            }
        }
        return false;
    }
};