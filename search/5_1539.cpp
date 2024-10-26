// leetcode #1539. 第 k 个缺失的正整数
// 二分查找 不变量问题

/*
对于每个元素 a_i，可以唯一确定到第 i 个元素为止缺失的元素数量为 p_i = a_i − i − 1
p_i是随 i 非严格递增的，可以使用二分查找解决这个问题。
只要找到一个 i 使得 p_(i−1) < k ≤ p_i，就可以确定缺失的第 k 个数为 k − p_(i−1) + a_(i−1)。
也就是说，要找到第一个大于等于 k 的 p_i
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if (arr[0] > k) return k;
        int l = 0, r = arr.size();
        while (l < r) {
            int mid = (l + r) >> 1;
            int x = mid < arr.size() ? arr[mid] : INT_MAX;
            if (x - mid - 1 >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return k - (arr[l - 1] - (l - 1) - 1) + arr[l - 1];
    }
};