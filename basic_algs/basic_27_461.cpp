//leetcode #461 汉明距离
// 异或和与的性质求解

#include <iostream>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        // 汉明距离 --- 两个数不一样的位的个数
        // 先异或 再求结果中的1的个数
        // 1的个数可以用 X&(X-1) 迭代实现

        int distance = 0;
        for(int x_or = x ^ y; x_or != 0; x_or &= (x_or - 1)) distance++; // 自顶向下 从自己到0迭代了几次就是几个1
        return distance;
    }
};