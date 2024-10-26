// leetcode #1351. 统计有序矩阵中的负数
// 二分查找

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), num = 0;
        for (int i = 0; i < m; i++) {
            int l = 0, r = grid[i].size() - 1, pos = -1;
            while (l <= r) {
                int mid = l + ((r - l) >> 1);
                if (grid[i][mid] <= -1 ) {
                    pos = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if (~pos) num += grid[i].size() - pos;  // ~ 表示按位取反 即当pos是-1的时候 pos的二进制表示是11111111.... 这种情况取反就是全0 不计入答案
        }
        return num;
    }
};