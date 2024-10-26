// leetcode #790 多米诺和托米诺平铺
// 二维dp

/*

在第 i 列前面的正方形都被瓷砖覆盖，在第 i 列后面的正方形都没有被瓷砖覆盖（i 从 1 开始计数）。那么第 i 列的正方形有四种被覆盖的情况：

一个正方形都没有被覆盖，记为状态 0；

只有上方的正方形被覆盖，记为状态 1；

只有下方的正方形被覆盖，记为状态 2；

上下两个正方形都被覆盖，记为状态 3。

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long MAXN = 1e9 + 7;
    int numTilings(int n) {
        vector<vector<long long>> dp(n + 1, vector<long long>(4)); // dp[i][s] 表示平铺到第i列时，各个状态s对应的平铺方法数量

        dp[0][3] = 1;
        for (int i = 1; i <= n; i++) {
                dp[i][0] = dp[i - 1][3] % MAXN;
                dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MAXN;
                dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MAXN;
                dp[i][3] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) % MAXN;
        }

        return dp[n][3];
    }
};