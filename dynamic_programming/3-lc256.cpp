// leetcode #256 粉刷房子
// 二维dp 

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int i, j, k;
        int n = costs.size();
        vector<vector<int>> dp(n, vector<int>(3)); // n个房子 3种颜色的二维dp

        for(int i = 0; i < 3; i++) {
            dp[0][i] = costs[0][i];
        }

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < 3; j++) {
                dp[i][j] = INT_MAX;
                for(int k = 0; k < 3; k++) {
                    if(k != j) dp[i][j] = min(dp[i][j], dp[i - 1][k] + costs[i][j]);
                }
            }
        }

        return min(min(dp[n-1][0], dp[n-1][1]), dp[n-1][2]);
    }
};