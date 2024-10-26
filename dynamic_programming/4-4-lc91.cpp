// leetcode #91 解码方法
// 一维dp - 分情况状态转移 - 字符串

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(101); // dp数组保存原码的每一位的解码方法数
        int n = s.size();

        for(int i = 0; i < n; i++) {
            dp[i] = 0;
            if(i == 0) dp[i] = (s[i] == '0') ? 0 : 1; // 考虑第一个字符为零的情况
            else {
                if(s[i] != '0') dp[i] += dp[i-1]; // 对于不为零的字符 肯定至少有前一位的方法数
                // 考虑1x和2x的情况 为零的字符肯定满足下面的条件
                if(i >= 1 && (s[i-1] == '1' || s[i-1] == '2')) {
                    int val = (s[i-1] - '0') * 10 + s[i] - '0'; // 排除掉 27 28 29 这三个无效情况
                    if(val <= 26) {
                        if(i == 1) dp[i]++;
                        else dp[i] += dp[i-2]; // 如果是满足有多解的情况 就是前一位和前两位的方法数之和
                    }
                }
            }
        }

        return dp[n-1];
    }
};