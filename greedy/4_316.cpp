// leetcode #321. 拼接最大数
// 贪心 + 单调栈

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> visited(26), num(26);
        for (char ch : s) {
            num[ch - 'a']++;
        }

        string stk;
        for (char ch : s) {
            if (!visited[ch - 'a']) {
                while (!stk.empty() && stk.back() > ch) {
                    // 如果后面没有栈顶元素了 就不能pop
                    if (num[stk.back() - 'a'] > 0) {
                        visited[stk.back() - 'a'] = 0;
                        stk.pop_back();
                    }
                    else break;
                }
                visited[ch - 'a'] = 1;
                stk.push_back(ch);
            }
            num[ch - 'a'] -= 1;
        }
        return stk;
    }
};