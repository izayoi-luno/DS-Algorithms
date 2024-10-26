// leetcode #1964 找出到每个位置为止最长的有效障碍赛跑路线
// 最长递增子序列 - 二分查找
// 类似于354

#include <iostream>
#include <vector>

using namespace std;

class Solution1 {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        if(obstacles.empty()) return {};
        int n = obstacles.size();
        vector<int> ans(n);

        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++) {
            int maxv = 1;
            for(int j = 0; j < i; j++) {
                if(obstacles[j] <= obstacles[i]) dp[i] = max(dp[i], dp[j] + 1);
            }
            maxv = max(maxv, dp[i]);
            ans[i] = maxv;
        }

        return ans;
    }
}; // 超时的解法

class Solution2 {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> dp, ans;
        for(int ob : obstacles) {
            if(dp.empty() || ob >= dp.back()) {
                dp.push_back(ob);
                ans.push_back(dp.size());
            }
            else {
                // 如果是最长严格递增子序列，这里是 lower_bound
                // 如果是最长递增子序列，这里是 upper_bound
                int it = upper_bound(dp.begin(), dp.end(), ob) - dp.begin();
                ans.push_back(it + 1);
                dp[it] = ob;
            }
        }
        return ans;
    }
}; // 经典二分+dp 可用于解决类似于300最长递增子序列这样的常规dp解法需要O(n2)的问题

