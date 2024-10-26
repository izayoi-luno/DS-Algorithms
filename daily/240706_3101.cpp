// leetcode #3101. 交替子数组计数
// 动态规划 - 子数组问题

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
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long cur = 0, res = 0;
        int pre = -1;
        for (int a : nums) {
            cur = pre != a ? cur + 1 : 1;
            pre = a;
            res += cur;
        }
        return res;
    }
};