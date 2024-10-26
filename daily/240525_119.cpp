// leetcode #119 杨辉三角 II
// 经典dp - 二维dp

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> dp;

        for(int i = 0; i <= rowIndex; i++) {
            vector<int> v;
            for(int j = 0; j <= i; j++) {
                if(j == 0 || j == i) v.push_back(1);
                else v.push_back(dp[i - 1][j - 1] + dp[i - 1][j]);
            }
            dp.push_back(v);
        }

        return dp[rowIndex];
    }
};