// leetcode #1738 找出第 K 大的异或坐标值
// 二维dp 位运算
// 二维前缀和

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) dp[i][j] = matrix[i][j];
                else if(i == 0) dp[i][j] = matrix[i][j] ^ dp[i][j - 1];
                else if(j == 0) dp[i][j] = matrix[i][j] ^ dp[i - 1][j];
                else dp[i][j] = matrix[i][j] ^ dp[i][j - 1] ^ dp[i - 1][j] ^ dp[i - 1][j - 1]; // 异或的逆运算还是异或
            }
        }

        vector<int> val;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                val.push_back(dp[i][j]);
            }
        }
        sort(val.begin(), val.end());

        return val[m * n - k];
    }
};