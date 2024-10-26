//leetcode #509 斐波那契数列
// 动态规划经典问题
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int fib(int n) {
        if(n == 0 || n == 1) return n;
        vector<int> result(n+1);
        result[0] = 0;
        result[1] = 1;
        for(int i = 2; i < n+1; i++) result[i] = result[i-1] + result[i-2];
        return result[n];
    }
};