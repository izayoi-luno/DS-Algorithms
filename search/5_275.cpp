// leetcode #275. H 指数 II
// 二分查找 不变量问题

/*
每次在查找范围内取中点 mid，则有 n−mid 篇论文被引用了至少 citations[mid] 次。
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (citations[mid] >= n - mid) r = mid - 1;
            else l = mid + 1;
        }
        return n - l;  // 注意h指数的定义
    }
};