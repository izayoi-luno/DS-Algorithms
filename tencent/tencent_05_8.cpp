//leetcode #8 Atoi字符串转整数算法
// 字符串由高位到地位的累加-含正负 处理边界问题

#include <iostream>
#include <climits>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int len = s.length();

        // 消除空格
        int index =0;
        while(index < len && s[index] == ' ') index++;
        if(index == len) return 0; // 相当于完全是空格

        // 判断符号
        int sign = 1;
        char firstChar = s[index];
        if(firstChar == '+') index++;
        else if(firstChar == '-') {
            index++;
            sign = -1;
        }

        // 结果记录
        int result = 0;
        while(index < len) {
            char chValue = s[index]; // 得到每一个字符
            if(chValue > '9' || chValue < '0') break; // 跳出循环
            // 处理边界条件 条件是越界的情况
            // 如果大于最大值整除10 说明result乘10后就绝对大于最大值了
            // 如果等于最大值整除10 说明result乘10后与最大值的差值需要大于等于再加上的那个值才能保证不越界
            if(result > INT_MAX / 10 || (result == INT_MAX / 10 && (chValue - '0') > INT_MAX % 10)) return INT_MAX;
            if(result < INT_MIN / 10 || (result == INT_MIN / 10 && (chValue - '0') > -(INT_MIN % 10))) return INT_MIN; // INT_MIN是负数

            // 字符串相减得到数值
            // 每一步都乘以sign -> 正数就是不断加 负数就是不断减
            /*
            147 -> 0 * 10 + 1 (1) -> 1 * 10 + 4 (14) -> 14 * 10 + 7 (147)
            */
            result = result * 10 + sign * (chValue - '0'); // 算法核心
            index++;
        }

        return result;

    }
};