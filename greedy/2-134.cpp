// leetcode #134. 加油站
// 标准贪心

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = 0;
        while (i < n) {
            int sumOfGas = 0, sumOfCost = 0;  // 用两个变量来保存油量和消耗
            int cnt = 0;
            while (cnt < n) {
                int j = (i + cnt) % n;
                sumOfGas += gas[j];
                sumOfCost += cost[j];
                if (sumOfCost > sumOfGas) break;  // *如果总油量小于总消耗则不可到达下一站
                cnt++;
            }
            if (cnt == n) return i;
            else i = i + cnt + 1;  // *如果i不能到达j+1，那么i到j都不能到达j+1
        }
        return -1;
    }
};