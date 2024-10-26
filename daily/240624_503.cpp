// leetcode #503. 下一个更大元素 II
// 单调栈 + 循环数组

/*
用单调栈避免遍历两次
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <map>
#include <numeric>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n, -1);
        stack<int> stk; // 单调栈保存下标
        for (int i = 0; i < n * 2 - 1; i++) {
            // 单调栈保证从栈顶到栈低单调递增，那么当新遍历到的数比栈顶小就入栈，否则依次出栈并记录（这个数就是之前保存在栈中的下一个更大元素），直到这个数不再比栈顶更大
            while (!stk.empty() && nums[stk.top()] < nums[i % n]) {
                ret[stk.top()] = nums[i % n];
                stk.pop();
            }
            stk.push(i % n);
        }
        return ret;
    }
};
