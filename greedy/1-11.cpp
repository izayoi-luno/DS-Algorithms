// leetcode #11. 盛最多水的容器
// 贪心 + 双指针

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while (l < r) {
            int area = min(height[l], height[r]) * (r - l);
            ans = max(ans, area);
            if (height[l] < height[r]) ++l;
            else --r;
        }
        return ans;
    }
};