// leetcode #115 不同的子序列
// 二维dp 字符串

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long MOD = 1e9 + 7;
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m < n) return 0;

        vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1)); // dp[i][j] 代表 t[j:] 在 s[i:] 的子序列中出现的次数
        for(int i = 0; i <= m; i++) {
            dp[i][n] = 1;
        }

        for(int i = m - 1; i >= 0; i--) {
            char sc = s[i];
            for(int j = n - 1; j >= 0; j--) {
                char tc = t[j];
                if(sc == tc) dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j]; // 与lc712类似 当s[i] == t[j]时 出现了公共元素 当前的子序列个数是 t[j] 在 s[i + 1] 子序列中的个数和 t[j + 1] 在 s[i + 1] 子序列中的个数
                else dp[i][j] = dp[i + 1][j];
            }
        }

        return dp[0][0];
    }
};