// leetcode #179. 最大数
// 贪心 + 排序

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        string res;
        for (int i = 0; i < nums.size(); ++i) {
            strs.push_back(to_string(nums[i]));
        }
        sort(strs.begin(), strs.end(), [](string& x, string& y) {return y + x < x + y; });  // 核心是解决遇到最高位相同的数应该怎么排序
        if (strs[0] == "0") return "0";
        for (int i = 0; i < strs.size(); ++i) {
            res.append(strs[i]);
        }
        return res;
    }
};