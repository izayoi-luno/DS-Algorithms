// leetcode #3099. 哈沙德数
// 数学 - 数位处理

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sm = 0;
        int num = x;
        while (num > 0) {
            sm += num % 10;
            num /= 10;
        }
        return x % sm == 0 ? sm : -1;
    }
};