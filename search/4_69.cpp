// leetcode #69. x 的平方根 
// 二分查找 + 数学
// 用二分查找的方式求平方根 / 判断是是否是完全平方数

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 1) return 1;
        int l = 1, r = x;
        while (l <= r) {
            long long mid = l + ((r - l) >> 1);
            if (mid * mid == x) return mid;
            if (mid * mid > x) r = mid - 1;
            else l = mid + 1;
        }
        return l - 1;  // 注意一下这里的指针位置
    }
};