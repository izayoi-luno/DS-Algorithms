// leetcode #1218 最长定差子序列
// 最长递增子序列
// 使用哈希表的dp

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        vector<int> dp(n, 1); // dp[i] 是 arr前i个区间的最长定差子序列长度

        int maxv = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(arr[i] - arr[j] == difference) dp[i] = max(dp[i], dp[j] + 1);
            }
            maxv = max(maxv, dp[i]);
        }

        return maxv;
    }
}; // 可惜要超时 时间复杂度为O(n2)

class Solution2 {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp; // dp[key] 是 以arr[i]结尾的最长定差子序列长度：dp[arr[i]]
        /*
        - 为什么不用数组？
        因为测试数据的范围有很大的负数值 需要处理数组下标越界的问题

        - 用arr值作为键来存储最长值 和 传统的用dp[i]表示[0:i]区间的区别/注意点在于
        这种方式没有保存原数组/字符串的顺序
        如果原数组/字符串的顺序不重要 则可放心使用这种方法
        否则要注意在将数组数据存入哈希表和进行状态转移的顺序问题
        */


        int n = arr.size();

        int maxv = 1;
        for(int i = 0; i < n; i++) {
            if(dp.find(arr[i]) == dp.end()) dp[arr[i]] = 1;
            if(dp.find(arr[i] - difference) != dp.end()) {
                dp[arr[i]] = max(dp[arr[i] - difference] + 1, dp[arr[i]]);
                maxv = max(maxv, dp[arr[i]]);
            }
        }

        if(difference == 0) maxv -= 1;
        
        return maxv;
    }
};