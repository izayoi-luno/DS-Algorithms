// leetcode #873 最长的斐波那契子序列的长度
// 最长递增子序列

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n)); // dp[i][j] 第j是最后一个数 第i是倒数第二个数 以这两个数为结尾的斐波那契子序列的长度

        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                int idx = findv(arr, 0, i - 1, arr[j] - arr[i]); // 二分查找找到倒数第三个数的位置
                if(idx != -1) dp[i][j] = dp[idx][i] + 1;
                else dp[i][j] = 2;
                res = max(res, dp[i][j]);
            }
        }

        return res >= 3 ? res : 0;
    
    }

    /* 实现二分查找 */
    int findv(vector<int>& arr, int l, int r, int val) {
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(val > arr[mid]) l = mid + 1;
            else if(val < arr[mid]) r = mid - 1;
            else return mid;
        }
        return -1;
    }
};