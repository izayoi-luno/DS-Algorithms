// leetcode #746 爬楼梯最小代价
// 递推

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> f(1001);
        int n = cost.size();
        f[0] = f[1] = 0;

        for(int i = 2; i <= n; i++) {
            f[i] = min(f[i-1] + cost[i-1], f[i-2] + cost[i-2]);
        }

        return f[n];
    }
};