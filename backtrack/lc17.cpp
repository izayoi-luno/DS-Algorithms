// leetcode #17. 电话号码的字母组合
// 回溯法

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
    unordered_map<char, string> alphabet;

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        initAlpha();
        vector<string> ans;
        string comb;
        backtrack(digits, ans, comb, 0);
        return ans;
    }

    void backtrack(string& digits, vector<string>& ans, string& comb, int idx) {
        if (idx == digits.size()) {
            ans.push_back(comb);
            return;
        }
        for (int i = 0; i < alphabet[digits[idx]].size(); i++) {
            comb.push_back(alphabet[digits[idx]][i]);
            backtrack(digits, ans, comb, idx + 1);
            comb.pop_back();
        }
    }

    void initAlpha() {
        alphabet['2'] = "abc";
        alphabet['3'] = "def";
        alphabet['4'] = "ghi";
        alphabet['5'] = "jkl";
        alphabet['6'] = "mno";
        alphabet['7'] = "pqrs";
        alphabet['8'] = "tuv";
        alphabet['9'] = "wxyz";
    }
};