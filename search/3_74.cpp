// leetcode #74. 搜索二维矩阵
// 矩阵二分查找

/*
先查找行再在行内查找会超时
所以直接将矩阵“拉直”成数组：不用真的拉直，而是将坐标进行变换即可
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, r = m * n - 1;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            int row = mid / n;
            int col = mid % n;
            if (matrix[row][col] == target) return true;
            if (matrix[row][col] > target) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
};