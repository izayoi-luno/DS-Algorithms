// leetcode #2466 统计构造好字符串的方案数
// 一维dp - 爬楼梯翻版

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int MOD = 1e9 + 7;
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1);
        int res = 0;

        dp[0] = 1;
        for(int i = 1; i <= high; i++) {
            if(i >= zero) dp[i] = (dp[i] + dp[i - zero]) % MOD;
            if(i >= one) dp[i] = (dp[i] + dp[i - one]) % MOD; // 和爬楼梯有个小区别  zero和one如果相等是可以重复转移计数的 而爬楼梯直接是两个不同的状态转移之和
            if(i >= low) res = (res + dp[i]) % MOD;
        }

        return res;
    }
};