// leetcode #2732. 找到矩阵中的好子集
// 构造

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        vector<int> ans;
        unordered_map<int, int> mp;
        int m = grid.size();
        int n = grid[0].size();

        for (int j = 0; j < m; j++) {
            int st = 0;
            for (int i = 0; i < n; i++) {
                st |= (grid[j][i] << i);
            }
            mp[st] = j;
        }

        if (mp.count(0)) {
            ans.push_back(mp[0]);
            return ans;
        }

        for (auto [x, i]: mp) {
            for (auto [y, j]: mp) {
                if (!(x & y)) {
                    return {min(i, j), max(i, j)};
                }
            }
        }

        return ans;
    }
};

/*
假设答案至少一行，那么需要这一行满足全为 0。

假设答案至少两行，那么不存在一列这两行都是 1。分别用 x 和 y 表示这两行所表示的数，能推出至少存在两行 x&y==0。

假设答案至少三行，那么这三行每一列加起来的和不超过 1。
这个条件比两行的情况更严格，如果两行都找不到答案，那么一定没有三行的情况了。

假设答案至少四行，那么这四行每一列加起来的和不超过 2。
如果两行找不到答案，说明任选两行至少存在一列这两行都是 1。同时这一列这两行已经都是 1 了，那么这一列的其他两行必须是 0 才满足条件。
所以，当答案有四行的情况下，需要满足任选两行这一列都是 1 同时其他两行必须是 0 至少需要 C42=6列，但题意说矩阵的列数 n<=5，因此这种情况不存在。

一般的，对于任意一行，假设答案至少需要选取 k 行。
考虑任选两行至少存在一列这两行都是 1 的构造，一共需要 k−1 对构造，当这一列选择了 1 后，其他 k−1 行最多有 k/2−1个 1，所以最多能贡献 k/2−1 个构造。
因为 k−1/(k/2−1)>2 ， 所以这一行至少需要 3 个 1 才能达到 k−1 个构造，同时因为列数不超过 5，所以至多有 2 列是 0。
因此任意一行 1 的个数比 0 更多，进而推出任选 k 行，1 的总数比 0 更多，无法找到一个合法的构造满足题意。

综上所述，只需要考虑答案小于等于两行的情况。每行二进制所表示的数一共有 2^n 种情况，其中 n 为矩阵的列数。

*/