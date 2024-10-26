//leetcode #2149 通过元素符号重排序数组
// 辅助数组

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int len = nums.size();
        vector<int> pos;
        vector<int> neg;
        vector<int> result;
        for(int i = 0; i < len; i++) {
            if(nums[i] > 0) pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }
        for(int i = 0; i < len; i++) {
            if(i % 2 == 0) result.push_back(pos[i / 2]);
            else result.push_back(neg[i / 2]);
        }
        return result;
    }
};