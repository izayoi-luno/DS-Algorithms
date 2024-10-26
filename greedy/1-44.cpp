// leetcode #44. 通配符匹配
// 贪心 + 双指针

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        while (s.size() && p.size() && p.back() != '*') {
            if (charMatch(s.back(), p.back())) {
                s.pop_back();
                p.pop_back();
            }
            else {
                return false;
            }
        }
        if (p.empty()) return s.empty();
        int sIndex = 0, pIndex = 0;
        int sRecord = -1, pRecord = -1;
        while (sIndex < s.size() && pIndex < p.size()) {
            if (p[pIndex] == '*') {
                ++pIndex;
                sRecord = sIndex;
                pRecord = pIndex;
            }
            else if (charMatch(s[sIndex], p[pIndex])) {
                ++sIndex;
                ++pIndex;
            }
            else if (sRecord != -1 && sRecord + 1 < s.size()) {
                ++sRecord;
                sIndex = sRecord;
                pIndex = pRecord;
            }
            else {
                return false;
            }
        }
        return allStars(p, pIndex, p.size());
    }

    bool charMatch(char u, char v) {
        return u == v || v == '?';
    }

    bool allStars(const string& str, int left, int right) {
        for (int i = left; i < right; ++i) {
            if (str[i] != '*') {
                return false;
            }
        }
        return true;
    }
};