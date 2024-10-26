// leetcode #436. 寻找右区间
// 二分查找

/*
给二维数组每个元素找对应的元素，暴力搜索的时间复杂度会很高
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> startIntervals;
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            startIntervals.emplace_back(intervals[i][0], i);
        }
        sort(startIntervals.begin(), startIntervals.end());

        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(startIntervals.begin(), startIntervals.end(), make_pair(intervals[i][1], 0));  // 注意lb和ub函数在比较目标值的时候的比较顺序
            if (it != startIntervals.end()) {
                ans[i] = it->second;
            }
        }
        return ans;
    }
};