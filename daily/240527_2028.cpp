// leetcode #2028 找出缺失的观测数据
// 数学 模拟

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        vector<int> res(n);

        int totalRoll = 0;
        for(int i = 0; i < m ; i++) {
            totalRoll += rolls[i];
        }
        
        int total = mean * (n + m);
        int totalLost = total - totalRoll;

        if(totalLost > 6 * n || totalLost < n) return {};

        int quotient = totalLost / n, remainer = totalLost % n; // 用整数的思维思考平均值的问题
        for(int i = 0; i < n; i++) {
            res[i] = quotient + (i < remainer ? 1 : 0);
        }

        return res;
    }
};