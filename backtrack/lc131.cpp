// leetcode #131. 分割回文串
// 回溯 + 子串分割问题

/*
这道题类似于lc93题
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
    vector<vector<string>> ans;
    vector<string> sol;
    vector<vector<string>> partition(string s) {    
        backtrack(s, 0);
        return ans;
    }

    void backtrack(string& s, int idx) {
        if (idx == s.size()) {
            ans.push_back(sol);
            return;
        }
        string pali;
        for (int i = idx; i < s.size(); i++) {
            pali.push_back(s[i]);
            if (isPalindrome(pali)) {
                sol.push_back(pali);
                backtrack(s, i + 1);
                sol.pop_back();
            } 
            else continue; // 这个地方是continue而不是break 因为回文串必须要先遍历到不是回文串的情况之后才能遍历到下一个答案
        }
    }

    bool isPalindrome(string str) {
        int n = str.size();
        int m = (n % 2 == 0 ? n / 2 : n / 2 + 1);
        for (int i = 0; i < m; i++) {
            if (str[i] == str[n - i - 1]) continue;
            else return false;
        }
        return true;
    }
};