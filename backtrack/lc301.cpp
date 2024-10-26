// leetcode #301. 删除无效的括号
// 回溯法 + 剪枝

/*
这道题类似于lc22

核心：
遍历一次输入字符串，统计「左括号」和「右括号」出现的次数。

1. 当遍历到「左括号」的时候：
「左括号」数量加 1。

2. 当遍历到「右括号」的时候：
- 如果此时「左括号」的数量不为 0，因为「右括号」可以与之前遍历到的「左括号」匹配，此时「左括号」出现的次数 −1；
- 如果此时「左括号」的数量为 0，「右括号」数量加 1。
*通过这样的计数规则，得到的「左括号」和「右括号」的数量就是各自 **最少** 应该删除的数量。
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
    vector<string> res;
    vector<string> removeInvalidParentheses(string s) {
        int lremove = 0;
        int rremove = 0;

        /*
        首先利用括号匹配的规则
        求出该字符串 s 中最少需要去掉的左括号的数目 lremove 
        和右括号的数目 rremove
        */
        for (char c : s) {
            if (c == '(') {
                lremove++;
            } else if (c == ')') {
                if (lremove == 0) {
                    rremove++;
                } else {
                    lremove--;
                }
            }
        }
        /*
        然后尝试在原字符串 s 中去掉 lremove 个左括号和 rremove 个右括号，
        然后检测剩余的字符串是否合法匹配
        */
        helper(s, 0, lremove, rremove);
        return res;
    }

    void helper(string str, int start, int lremove, int rremove) {
        if (lremove == 0 && rremove == 0) {
            if (isValid(str)) {
                res.push_back(str);
            }
            return;
        }
        for (int i = start; i < str.size(); i++) {
            if (i != start && str[i] == str[i - 1]) {
                continue;
            }
            // 如果剩余的字符无法满足去掉的数量要求，直接返回
            if (lremove + rremove > str.size() - i) {
                return;
            } 
            // 尝试去掉一个左括号
            if (lremove > 0 && str[i] == '(') {
                helper(str.substr(0, i) + str.substr(i + 1), i, lremove - 1, rremove);  // 使用 substr 方法 
            }
            // 尝试去掉一个右括号
            if (rremove > 0 && str[i] == ')') {
                helper(str.substr(0, i) + str.substr(i + 1), i, lremove, rremove - 1);
            }
        }
    }

    inline bool isValid(const string & str) {
        int cnt = 0;

        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(') {
                cnt++;
            } else if (str[i] == ')') {
                cnt--;
                if (cnt < 0) {
                    return false;
                }
            }
        }

        return cnt == 0;
    }
};