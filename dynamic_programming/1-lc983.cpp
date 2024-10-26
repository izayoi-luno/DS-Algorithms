// leetcode #983 最低票价
// 一维dp - 倒序递推
// 记忆化搜索

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution1 {
public:
    unordered_set<int> daySet;

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        for(int day : days) daySet.insert(day);
        vector<int> dp(396);
        for(int i = 395; i >= 1; i--) {
            if(i > 365) dp[i] = 0;
            else if(daySet.count(i)) dp[i] = min(min(dp[i + 1] + costs[0], dp[i + 7] + costs[1]), dp[i + 30]+ costs[2]); // 贪心 只在当天买 买了之后 1/7/30天后就不用再买了
            else dp[i] = dp[i + 1];
        }

        return dp[1];
    }
};

class Solution2 {
public:
    unordered_set<int> daySet;
    vector<int> costs;
    int memo[366];

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        this->costs = costs;
        memset(memo, -1, sizeof(memo));
        for(int day : days) daySet.insert(day);
        return dp(1);
    }

    int dp(int i) {
        if(i > 365) return 0;
        if(memo[i] != -1) return memo[i];
        if(daySet.count(i)) memo[i] = min(min(dp(i + 1) + costs[0], dp(i + 7) + costs[1]), dp(i + 30)+ costs[2]);
        else memo[i] = dp(i + 1);
        return memo[i];
    }
};