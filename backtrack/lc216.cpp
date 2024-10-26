// leetcode #216. 组合总和 III
// 回溯法

/*
lc40题的继续
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
    vector<vector<int>> ans;
    vector<int> comb;
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(k, n, 1);
        return ans;
    }

    void backtrack(int k, int n, int idx) {
        if (comb.size() == k && n == 0) {
            ans.push_back(comb);
            return;
        }
        for (int i = idx; i < 10; i++) {
            if (n - i >= 0) {
                comb.push_back(i);
                backtrack(k, n - i, i + 1);
                comb.pop_back();
            }
        }
    }
};