// leetcode #1869 哪种连续子字符串更长
// 一维dp / 伪二维dp - 前缀和

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkZeroOnes(string s) {
        int n = s.size();
        vector<vector<int>> dp(2, vector<int>(n)); // 两个数组分别保存0的个数和1的个数
        vector<int> maxv(2); // 保存0的最大个数和1的最大个数

        dp[s[0] - '0'][0] = 1;
        maxv[s[0] - '0'] = 1;
        for(int i  = 1; i < n; i++) {
            if(s[i] == s[i-1]) dp[s[i] - '0'][i] = dp[s[i] - '0'][i-1] + 1;
            else dp[s[i] - '0'][i] = 1;

            maxv[0] = max(maxv[0], dp[0][i]);
            maxv[1] = max(maxv[1], dp[1][i]);
        }

        return maxv[1] > maxv[0];
    }
};