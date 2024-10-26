// leetcode #516 最长回文子序列
// 最长公共子序列 - 可以将问题转化为一个串和他的逆序串求最长公共子序列

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return longestCommonSubsequence(s, t);
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m)); // text1的第i个数和text2的第j个数的最长公共子序列长度

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int same = (text1[i] == text2[j]) ? 1 : 0;
                if(i == 0 && j == 0) dp[i][j] = same;
                else if(i == 0) dp[i][j] = dp[i][j - 1] || same;
                else if(j == 0) dp[i][j] = dp[i - 1][j] || same;
                else if(same) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n - 1][m - 1];
    }
};