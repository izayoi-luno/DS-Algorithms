// leetcode #679. 24 点游戏
// 回溯法

/*
这道题类似于lc282

可以通过回溯的方法遍历所有不同的可能性。
具体做法是，使用一个列表存储目前的全部数字，
每次从列表中选出 2 个数字，再选择一种运算操作，用计算得到的结果取代选出的 2 个数字，这样列表中的数字就减少了 1 个。
重复上述步骤，直到列表中只剩下 1 个数字，这个数字就是一种可能性的结果，如果结果等于 24，则说明可以通过运算得到 24。
如果所有的可能性的结果都不等于 24，则说明无法通过运算得到 24。

注意点：
1. 所有的运算都是浮点数运算，判断相等的时候要用epsilon判断精度
2. 除法不能除以0，做除法的时候要判断
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
#include <set>

using namespace std;

class Solution {
public:
    static constexpr int TARGET = 24;
    static constexpr double EPSILON = 1e-6;
    static constexpr int ADD = 0, MULTIPLY = 1, SUBTRACT = 2, DIVIDE = 3;

    bool judgePoint24(vector<int> &nums) {
        vector<double> l;
        for (const int &num : nums) {
            l.emplace_back(static_cast<double>(num));
        }
        return solve(l);
    }

    bool solve(vector<double> &l) {
        if (l.size() == 0) {
            return false;
        }
        if (l.size() == 1) {
            return fabs(l[0] - TARGET) < EPSILON;
        }
        // 选两个不同的数
        int size = l.size();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i != j) {
                    // 把列表中剩下的数先装起来
                    vector<double> list2 = vector<double>();
                    for (int k = 0; k < size; k++) {
                        if (k != i && k != j) {
                            list2.emplace_back(l[k]);
                        }
                    }
                    // 枚举运算并将结果写回列表
                    for (int k = 0; k < 4; k++) {
                        // 跳过加法和乘法的重复
                        if (k < 2 && i > j) {
                            continue;
                        }
                        if (k == ADD) {
                            list2.emplace_back(l[i] + l[j]);
                        } else if (k == MULTIPLY) {
                            list2.emplace_back(l[i] * l[j]);
                        } else if (k == SUBTRACT) {
                            list2.emplace_back(l[i] - l[j]);
                        } else if (k == DIVIDE) {
                            if (fabs(l[j]) < EPSILON) {
                                continue;
                            }
                            list2.emplace_back(l[i] / l[j]);
                        }
                        // 进行回溯递归
                        if (solve(list2)) {
                            return true;
                        }
                        list2.pop_back();
                    }
                }
            }
        }
        return false;
    }
};