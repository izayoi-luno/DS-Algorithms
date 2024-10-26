//leetcode #415 字符串相加
// 不使用字符串转整数 和 #2 链表两数相加类似

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string result;
        int add = 0; // 进位
        // 倒序遍历字符串
        for(int i = num1.size()-1, j = num2.size()-1; i >= 0 || j >=0 || add == 1; i--, j--) {
            int x = i < 0 ? 0 : num1[i] - '0'; // 判断指针是否越界
            int y = j < 0 ? 0 : num2[j] - '0';
            int newBit = (x + y + add) % 10;
            result.append(to_string(newBit));
            add = (x + y + add) / 10;
        }
        reverse(result.begin(), result.end());
        return result;

    }
};