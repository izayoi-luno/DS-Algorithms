// leetcode #282. 给表达式添加运算符
// 回溯法 + 子串分割问题

/*
这道题类似于lc93、lc131

难点不在于回溯，而是字符串分割处理 和 整型变量运算的转化问题

小技巧：
1. 先给运算符占位，规避使用字符串push和pop操作进行复杂的变换
2. 表达式插入值的时候每循环一次就添加一位，不用考虑一次性加入一整个 val 的字符串，规避麻烦的字符串加减操作
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
    vector<string> ans;
    vector<string> addOperators(string num, int target) {
        string expr;  // expr 为当前构建出的表达式；
        backtrack(expr, 0, 0, 0, num, target);
        return ans;
    }
    
    // res 为当前表达式的计算结果；
    // mul 为表达式最后一个连乘串的计算结果
    void backtrack(string &expr, int i, long res, long mul, string& num, int& target) {
        if (i == num.size()) {
            if (res == target) {
                ans.emplace_back(expr);
            }
            return;
        }
        int signIndex = expr.size();
        if (i > 0) {
            expr.push_back(0); // 占位，下面填充符号
        }
        long val = 0;
        // 枚举截取的数字长度（取多少位），注意数字可以是单个 0 但不能有前导零
        for (int j = i; j < num.size() && (j == i || num[i] != '0'); ++j) {
            val = val * 10 + num[j] - '0';
            expr.push_back(num[j]);
            if (i == 0) { // 表达式开头不能添加符号
                backtrack(expr, j + 1, val, val, num, target);
            } else { // 枚举符号
                expr[signIndex] = '+'; backtrack(expr, j + 1, res + val, val, num, target);
                expr[signIndex] = '-'; backtrack(expr, j + 1, res - val, -val, num, target);
                expr[signIndex] = '*'; backtrack(expr, j + 1, res - mul + mul * val, mul * val, num, target);
                /*
                核心：
                若添加 * 号，由于乘法运算优先级高于加法和减法运算，我们需要对 res 撤销之前 mul 的计算结果，
                并添加新的连乘结果 mul∗val，也就是将 res 减少 mul 并增加 mul∗val。
                */

            }
        }
        expr.resize(signIndex);
    };

};