// leetcode #139 单词拆分
// 一维dp - O(n) - 字符串

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n, 0); // dp数组保存到s的每一位之前可以匹配的布尔值

        int i, j, k, l;
        for(i = 0; i < n; i++) {
            for(j = 0; j < wordDict.size(); j++) {
                l = wordDict[j].size();

                // 当前字典单词太长 跳过匹配
                if(i + 1 - l < 0 ) continue;
                // 前i - l位不能匹配 跳过匹配
                if(i + 1 - l != 0 && dp[i - l] == 0) continue;
                // 否则按位匹配 一旦不一样就break
                for(k = 0; k < l ; k++) {
                    if(s[i + 1 - l + k] != wordDict[j][k]) break;
                }
                // 如果没有break说明匹配成功 上面循环完整执行 k == l为true
                if(k == l) {
                    dp[i] = 1;
                    break;
                }
            }
        }

        return dp[n - 1];
    }
};