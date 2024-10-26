// leetcode #401. 二进制手表
// 位运算 + 枚举

/*
小时由 4 个比特表示，分钟由 6 个比特表示，比特位值为 0 表示灯灭，为 1 表示灯亮。
枚举所有情况，数每种情况中二进制1的个数，如果个数等于目标数就是一个答案
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
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    ans.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
                }
            }
        }
        return ans;
    }
};