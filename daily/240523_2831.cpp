// leetcod #2831 找出最长等值子数组
// 滑窗 + 哈希表

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> pos;

        for(int i = 0; i < n; i++) pos[nums[i]].emplace_back(i); // 记录每种数出现的位置

        int res = 0;
        for(auto& pair: pos) {
            vector<int> vec = pair.second;
            /* 滑动窗口 */
            for(int i = 0, j = 0; i < vec.size(); i++) {
                while(vec[i] - vec[j] + 1 - (i - j + 1) > k) j++; // 只有当滑窗内部需要删除的数的个数大于k时才移动窗口左边 即不用枚举每种区间
                res = max(res, i - j + 1);
            }
        }

        return res;
    }
};