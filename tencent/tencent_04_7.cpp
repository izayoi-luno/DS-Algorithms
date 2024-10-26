//leetcode #7 反转整数
// 注意反转时候的溢出条件 比如反转前在i32的范围内而反转后超越了i32的范围

#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if(x == 0) return 0;
        int rev = 0;
        while(x != 0) {
            int m = x % 10;
            if(rev > 2147483647 / 10 || (rev == 2147483647 / 10 && m > 2147483647 % 10)) return 0;
            if(rev < -2147483648 / 10 || (rev == -2147483648 / 10 && m < -2147483648 % 10)) return 0;
            rev = rev * 10 + m;
            x /= 10;
        }
        return rev;
    }
};