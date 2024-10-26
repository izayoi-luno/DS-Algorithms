// leetcod #2981 找出出现至少三次的最长特殊子字符串 I
// 哈希表

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int maximumLength(string s) {
        int ans = -1;
        int n = s.size();
        unordered_map<string, int> helper;

        string key;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(s[j] != s[i]) break;
                key = s.substr(i, j - i + 1);
                helper[key]++;
                if(helper[key] >= 3) ans = max(ans, (int)key.size());
            }
        }

        return ans;
    }
};