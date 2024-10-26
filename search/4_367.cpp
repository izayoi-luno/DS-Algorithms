// leetcode #367. 有效的完全平方数
// 二分查找 + 数学
// 用二分查找的方式求平方根 / 判断是是否是完全平方数

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
        int l = 1, r = num;
        while (l <= r) {
            long long mid = l + ((r - l) >> 1);
            if (mid * mid == num) return true;
            if (mid * mid > num) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
};