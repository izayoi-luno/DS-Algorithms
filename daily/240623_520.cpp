// leetcode #520. 检测大写字母
// 字符串

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
    bool detectCapitalUse(string word) {
        if (word.size() == 1) return true;
        int isCap = 0;
        int cap = 0;
        int sml = 0;
        if (word[0] >= 'A' && word[0] <= 'Z') isCap = 1;
        for (int i = 1; i < word.size(); i++) {
            if (word[i] >= 'A' && word[i] <= 'Z') cap = 1;
            if (word[i] >= 'a' && word[i] <= 'z') sml = 1;
        }
        return (isCap && (cap && !sml) || (!cap && sml)) || (!isCap && !cap);
    }
};