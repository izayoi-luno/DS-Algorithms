//leetcode #338 比特位计数
// 按位与的特性进行求解 分治或动规

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        // 利用按位与的特性 X&(X-1)可以用来清除X的最低位的一个1
        // 循环或递归这个特性每次可以清除一个1得到比X小的数
        // 最后得到0 可以反过来推导X中1的个数 --- X中1的个数 = X&(X-1)中1的个数 + 1

        vector<int> bits(n + 1); // 创建一个大小为n+1的数组 每个元素是对应数的1个数
        for(int i = 1; i < n + 1; i++) bits[i] = bits[i & (i - 1)] + 1; // 动态规划思想 自底到顶方法
        return bits;
    }
};