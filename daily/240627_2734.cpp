// leetcode #2734. 执行子串操作后的字典序最小字符串
// 贪心 + 字符串

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    string smallestString(string s) {
        char target = 'a';
        auto it = std::find_if(s.begin(), s.end(), [target](char c) {
            return c != target;
        }); 
        int indexOfFirstNonA = std::distance(s.begin(), it);
        if (indexOfFirstNonA == s.length()) {
            return s.substr(0, s.length() - 1) + 'z';
        }
        size_t indexOfFirstA_AfterFirstNonA = s.find('a', indexOfFirstNonA);
        if (indexOfFirstA_AfterFirstNonA == string::npos) {
            indexOfFirstA_AfterFirstNonA = s.length();
        }
        string res;
        for (int i = 0; i < s.length(); ++i) {
            if (indexOfFirstNonA <= i && i < indexOfFirstA_AfterFirstNonA) {
                res.push_back(static_cast<char>(s[i] - 1));
            } else {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};