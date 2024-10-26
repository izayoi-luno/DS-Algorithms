// leetcode #374. 猜数字大小
// 标准二分查找

#include <iostream>
#include <vector>

using namespace std;

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (guess(mid) == 0) return mid;
            if (guess(mid) > 0) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
};