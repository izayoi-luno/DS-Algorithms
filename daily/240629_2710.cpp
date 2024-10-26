// leetcode #2710. 移除字符串中的尾随零
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
    string removeTrailingZeros(string num) {
        int n = num.size();
        int m = n;
        for (int i = n - 1; i >= 0; i--) {
            if (num[i] != '0') {
                m = i;
                break;
            } 
        }
        return num.substr(0, m + 1);
    }
};