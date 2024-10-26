// leetcode #LCP 61. 气温变化趋势
// 数组

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <map>
#include <numeric>

using namespace std;

class Solution {
public:
    int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB) {
        int m = temperatureA.size();
        vector<int> trendA(m - 1);
        vector<int> trendB(m - 1);
        for (int i = 0; i < m - 1; i++) {
            if (temperatureA[i + 1] - temperatureA[i] > 0) trendA[i] = 1;
            if (temperatureA[i + 1] - temperatureA[i] == 0) trendA[i] = 0;
            if (temperatureA[i + 1] - temperatureA[i] < 0) trendA[i] = -1;
            if (temperatureB[i + 1] - temperatureB[i] > 0) trendB[i] = 1;
            if (temperatureB[i + 1] - temperatureB[i] == 0) trendB[i] = 0;
            if (temperatureB[i + 1] - temperatureB[i] < 0) trendB[i] = -1;
        }
        int res = 0;
        for (int i = 0; i < m - 1; i++) {
            int same = 0;
            while (i < m - 1 && trendA[i] == trendB[i]) {
                same++;
                i++;
            }
            res = max(res, same);
        }
        return res;
    }
};