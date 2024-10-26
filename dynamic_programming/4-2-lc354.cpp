// leetcode #354 俄罗斯套娃信封问题
// 最长递增子序列 - 二分查找
//有点类似 646 1218

/*
为什么要二分查找？
因为测试数据很大 超出了常规的动态规划算法能解决的状态数
换句话来说 dp在这个时候没有复杂度优势
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        vector<int> dp(n, 1);
        sort(envelopes.begin(), envelopes.end());

        int maxv = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxv = max(maxv, dp[i]);
        }

        return maxv;
    }
}; // 超时的解法

class Solution2 {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.empty()) return 0;

        int n = envelopes.size();

        /*
        使用 sort 函数对 envelopes 进行自定义排序。
        首先按信封的宽度（e1[0]）进行升序排序。
        如果两个信封的宽度相同，则按信封的高度（e1[1]）进行降序排序。

        这样只用判断 envelopes[i][1] 即可
        */
        sort(envelopes.begin(), envelopes.end(), [](const auto& e1, const auto& e2) {
            return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
        }); 

        vector<int> dp = {envelopes[0][1]};
        for(int i = 1; i < n; i++) {
            int num = envelopes[i][1];
            if(num > dp.back()) dp.push_back(num);
            else {
                auto it = lower_bound(dp.begin(), dp.end(), num);
                *it = num;
            }
        }

        return dp.size();
    }
};

