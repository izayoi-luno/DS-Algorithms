// leetcode #2713. 矩阵中严格递增的单元格数
// 最长递增子序列

/*
设 d[i][j] 为移动到单元格 (i, j) 的最大步数，其中 (i, j)可以作为起始单元格，也可以是从其他单元格移动而来。
那么我们会考虑从第 i 行以及第 j 列上矩阵数值小于 mat[i][j] 的位置进行转移，即取以下数值中的最大值：

第 i 行：max(d[i][j'] + 1)，其中 mat[i][j′]<mat[i][j]；
第 j 列：max(d[i'][j] + 1)，其中 mat[i′][j]<mat[i][j]。
*因此，整个状态空间在进行转移时是有序的，我们可以对 mat 进行排序，从小到大进行转移。
*也就是把矩阵网格的状态转移变成了类似于线性表的转移
但在转移时，每个状态都要扫描一遍对应的行和列，时间复杂度为 O(n + m)，而整体求解的时间复杂度为 O(nm(n+m))，可能会超时，因此需要进行优化。

考虑到所有的 d[i][j] 在更新时，值只会越来越大，
而转移过程中我们只考虑对应行和对应列上 d 的最大值（由于大于 mat[i][j] 的位置还未遍历到，它们的状态还未更新，可设置为 0）。
因此，设置长度为 m 的数组 row 来维护每一行 d 的最大值，设置长度为 n 的数组 col 来维护每一列的最大值，这样一来：

d[i][j]=max⁡(row[i],col[j])+1

在每次更新了 d[i][j] 后，需要更新 row[i] 和 col[j]。
*另外需要注意的是，由于 mat 中可能包含相同数字，我们需要同时更新它们的 d 值，然后再同时更新它们对应的 row 和 col。

细节
*代码实现时 d[i][j] 可以省略，因为只需要知道每行每列的 d 值的最大值。
对于相同元素，先计算出 (i,j) 处的最大值，再更新到 row 和 col 中。
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        map<int, vector<pair<int, int>>> mp; // 在这里使用map红黑树而不是unordered_map哈希表 因为要对矩阵值进行排序
        vector<int> row(m), col(n);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[mat[i][j]].push_back({i, j});
            }
        }

        vector<int> res; // 存放相同数值的答案，便于后续更新 row 和 col
        for (auto &[_, pos] : mp) {
            res.clear();
            for (auto &[x, y] : pos) {
                res.push_back(max(row[x], col[y]) + 1);
            }
            for (int i = 0; i < pos.size(); i++) {
                auto &[x, y] = pos[i];
                row[x] = max(row[x], res[i]);
                col[y] = max(col[y], res[i]);
            }
        }

        return *max_element(row.begin(), row.end());
    }
};
