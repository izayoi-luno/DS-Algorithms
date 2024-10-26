// leetcode #691. 贴纸拼词
// 状压dp - 完全背包问题

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int m;
    int minStickers(vector<string>& stickers, string target) {
        m = target.size();
        vector<int> dp(1 << m, -1);
        dp[0] = 0;
        int res = helper((1 << m) - 1, dp, stickers, target);
        return res > m ? -1 : res;
    }

    int helper(int mask, vector<int>& dp, vector<string>& stickers, string target) {
        if (dp[mask] != -1) {
            return dp[mask];
        }
        dp[mask] = m + 1;
        for (auto & sticker : stickers) {
            int left = mask;
            vector<int> cnt(26);
            for (char & c : sticker) {
                cnt[c - 'a']++;
            }
            for (int i = 0; i < m; i++) {
                if ((mask >> i & 1) && cnt[target[i] - 'a'] > 0) {
                    cnt[target[i] - 'a']--;
                    left ^= 1 << i;
                }
            }
            if (left < mask) {
                dp[mask] = min(dp[mask], helper(left, dp, stickers, target) + 1);
            }
        }
        return dp[mask];
    }
};