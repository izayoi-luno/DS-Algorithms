// leetcode #1029 两地调度
// 贪心

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        int sum = 0;

        for(int i = 0; i < n; i++) sum += costs[i][0]; // 假设先全部送往A 那么有一半的人需要调度到B

        vector<int> refund;
        for(int i = 0; i < n; i++) {
            int ref = costs[i][1] - costs[i][0]; // 如果去B的花费比去A低 就调度去A 但是可能有超过一半的人都是B比A低 或者只有不到一半的人A比B低
            refund.push_back(ref);
        }

        sort(refund.begin(), refund.end()); // 排序 这样就取低的最多的n/2个人去B

        for(int i = 0; i < n / 2; i++) sum += refund[i];

        return sum;
    }
};