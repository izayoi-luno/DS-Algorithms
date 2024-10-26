// leetcode #279 完全平方数
// 经典dp - 完全背包问题

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX - 1);

        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            int ele = i * i;
            if(ele > n) break;
            for(int j = ele; j <= n; j++) {
                dp[j] = min(dp[j], dp[j - ele] + 1);
            }
        }

        return dp[n];
    }
};