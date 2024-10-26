// leetcode #1035 不相交的线
// 最长公共子序列 - 最长公共子序列

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m, vector<int>(n));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int same = (nums1[i] == nums2[j]) ? 1 : 0;
                if(i == 0 && j == 0) dp[i][j] = same;
                else if(i == 0) dp[i][j] = same || dp[i][j - 1];
                else if(j == 0) dp[i][j] = same || dp[i - 1][j];
                else if(same) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); 
            }
        }

        return dp[m - 1][n - 1];
    }
};