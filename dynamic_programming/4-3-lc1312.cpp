// leetcode #1312 让字符串成为回文串的最少插入次数
// 最长公共子序列
/*
可以将问题转化为一个串和他的逆序串求最长公共子序列 求到最长回文子序列的长度 
然后用原字符串长度减去这个最长子序列长度就是要插入的值
*/ 

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int minInsertions(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int maxNum = longestCommonSubsequence(s, t);
        return s.size() - maxNum;
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m));

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