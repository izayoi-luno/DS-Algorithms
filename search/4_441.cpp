// leetcode #441. 排列硬币
// 二分查找 + 数学
// 用二分查找的方式求等差数列相关问题

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = (right - left + 1) / 2 + left;
            if ((long long) mid * (mid + 1) <= (long long) 2 * n) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};