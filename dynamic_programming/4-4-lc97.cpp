// leetcode #97 交错字符串
// 二维dp - 字符串

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), t = s3.size();
        if(n + m != t) return false;

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, false)); // dp[i][j]表示s1的前i个子串和s2的前j个子串能否组成s3的前i+j个子串
        
        dp[0][0] = true;
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                int p = i + j - 1;
                if(i > 0) dp[i][j] |= (dp[i - 1][j] && s1[i - 1] == s3[p]);
                if(j > 0) dp[i][j] |= (dp[i][j - 1] && s2[j - 1] == s3[p]);
            }
        }

        return dp[n][m];
    }
};