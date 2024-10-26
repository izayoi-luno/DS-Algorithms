// leetcode #712 两个字符串的最小ASCII删除和
// 二维dp 字符串

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1)); // 注意dp数组的长度

        /*
        dp[i][j] 代表使得 s1[0 : i] 和 s2[0 : j] 相同的最小删除和 
        注意区间是左闭右开 这样当 i 或 j 等于 0 时 区间就是空字符串  dp[0][0] 就代表两个空串的删除和
        因为要考虑空串的问题 所以dp数组长度是字符串长度 +1
        在访问字符串的时候 按照正常索引 i - 1 或者 j - 1 访问 此时要注意字符串下标和dp数组下标的对应 
        如 s1[i - 1] 代表 s1 的第 i 个字符 那么对应到dp数组中就是 dp[i][x]

        考虑此类问题时 dp的长度和下标的对应是常见的细节考虑
        */

        for(int i = 1; i <= m; i++) dp[i][0] = dp[i - 1][0] + s1[i - 1];
        for(int j = 1; j <= n; j++) dp[0][j] = dp[0][j - 1] + s2[j - 1];
        for(int i = 1; i <= m; i++) {
            char c1 = s1[i - 1];
            for(int j = 1; j <= n; j++) {
                char c2 = s2[j - 1];
                if(c1 == c2) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
            }
        }

        return dp[m][n];
    }
};