// leetcode #474 一和零
// 经典三维dp - 0-1背包问题

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(m + 1, vector<int>(n + 1))); // dp[l][i][j] 表示在前 l 个字符串中，使用 i 个 0 和 j 个 1 的情况下最多可以得到的字符串数量

        for(int l = 1; l <= len; l++) {
            vector<int>&& zerosOnes = getZerosOnes(strs[l - 1]);
            int zeros = zerosOnes[0], ones = zerosOnes[1];
            for(int i = 0; i <= m; i++) {
                for(int j = 0; j <= n; j++) {
                    dp[l][i][j] = dp[l - 1][i][j];
                    if(i >= zeros && j >= ones) dp[l][i][j] = max(dp[l][i][j], dp[l - 1][i - zeros][j - ones] + 1);
                }
            }
        }

        return dp[len][m][n];
    }

    vector<int> getZerosOnes(string& str) {
        vector<int> zerosOnes(2);
        int len = str.size();
        for(int i = 0; i < len; i++) zerosOnes[str[i] - '0'] ++;
        return zerosOnes;
    }
};