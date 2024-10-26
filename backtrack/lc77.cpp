// leetcode #77. 组合
// 回溯法

/*
这道题与lc39题类似
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <map>
#include <numeric>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> combination;
        vector<int> interval;
        for (int i = 1; i <= n; i++) {
            interval.push_back(i);
        }
        backtrack(ans, combination, interval, k, 0);
        return ans;
    }

    void backtrack(vector<vector<int>>& ans, vector<int>& combination, vector<int>& interval, int k, int idx) {
        if (combination.size() == k) {
            ans.push_back(combination);
            return;
        }
        for (int i = idx; i < interval.size(); i++) {
            combination.push_back(interval[i]);
            backtrack(ans, combination, interval, k, i + 1);
            combination.pop_back();
        }
    }
};