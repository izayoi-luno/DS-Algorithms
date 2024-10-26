//leetcode #20 有效的括号
//简易版括号匹配 使用栈的LIFO特性 后进的括号要先匹配

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk; // 用一个栈来存放与左括号相匹配的右括号 遇到右括号就匹配
        for(char c : s) {
            if(c == '(') stk.push(')');
            else if(c == '[') stk.push(']');
            else if(c == '{') stk.push('}');
            else if(stk.empty() || stk.top() != c) return false; // 匹配不过就false 栈空了也false--相当于原字符串多了右括号()()]{}
            else stk.pop();
        }
        return stk.empty(); // 最后如果栈空说明匹配完成 栈没空说明原字符串最后多了左括号
    }
};