// leetcode #2140 解决智力问题
// 一维dp - 倒序递推

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1); // dp[i] 表示解决或不解决第 i 道题目及以后的题目可以获得的最高分数

        // 倒序遍历时间复杂度为O(n) 正序的话复杂度至少为O(n2)
        for(int i = n - 1; i >= 0; i--) {
            dp[i] = max(dp[i + 1], questions[i][0] + dp[min(n, i + questions[i][1] + 1)]);
        }

        return dp[0];
    }
};