// leetcode #744. 寻找比目标字母大的最小字母
// 二分查找

/*
找元素
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char> &letters, char target) {
        return target < letters.back() ? *upper_bound(letters.begin(), letters.end() - 1, target) : letters[0];
    }
};