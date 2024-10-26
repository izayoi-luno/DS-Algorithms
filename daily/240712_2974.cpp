// leetcode #2974. 最小数字游戏
// 排序

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i += 2) {
            swap(nums[i], nums[i + 1]);
        }
        return nums;
    }
};