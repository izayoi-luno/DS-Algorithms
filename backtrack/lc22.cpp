// leetcode #22. 括号生成
// 回溯法

/*
这道题的核心在于括号的有效性 然后是回溯分支条件判定
在写括号的时候 有效的括号一定是一开始先写左括号再写右括号
即一个右括号之前一定有一个左括号

那么在回溯递归的过程中 当左括号数量等于右括号的数量时 只能写左括号
当左括号的数量大于右括号的数量时 可以写右括号
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
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string comb;
        backtrack(ans, comb, 0, 0, n);
        return ans;
    }

    void backtrack(vector<string>& ans, string& comb, int left, int right, int n) {
        if (comb.size() == 2 * n) {
            ans.push_back(comb);
            return;
        }
        if (left < n) {
            comb.push_back('(');
            backtrack(ans, comb, left + 1, right, n);
            comb.pop_back();
        }
        if (right < left) {
            comb.push_back(')');
            backtrack(ans, comb, left, right + 1, n);
            comb.pop_back();
        }
    }
};