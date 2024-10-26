// leetcode #278. 第一个错误的版本
// 标准二分查找

/*
二分要注意的是while条件是小于还是小于等于
1. 小于的时候一般是让 r = mid 而让 l = mid + 1 或者让 r = mid - 1 而让 l = mid 这样当循环退出时找到的那个一定是l == r的那个元素
2. 小于等于的时候一般是让 r = mid - 1 而让 l = mid + 1 并在每次循环的时候检查nums[mid]是否是目标 
*/

#include <iostream>
#include <vector>

using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (isBadVersion(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};