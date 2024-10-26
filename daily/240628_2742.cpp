// leetcode #2742. 给墙壁刷油漆
// 动态规划

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<int> f(n * 2 + 1, INT_MAX / 2);
        f[n] = 0;
        for (int i = 0; i < n; ++i) {
            vector<int> g(n * 2 + 1, INT_MAX / 2);
            for (int j = 0; j <= n * 2; ++j) {
                // 付费
                g[min(j + time[i], n * 2)] = min(g[min(j + time[i], n * 2)], f[j] + cost[i]);
                // 免费
                if (j > 0) {
                    g[j - 1] = min(g[j - 1], f[j]);
                }
            }
            f = move(g);
        }
        return *min_element(f.begin() + n, f.end());
    }
};
