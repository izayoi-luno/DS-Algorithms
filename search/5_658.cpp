// leetcode #658. 找到 K 个最接近的元素
// 二分查找 + 双指针

/*
注意答案的个数
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int r = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int l = r - 1;
        while (k--) {
            if (l < 0) r++;
            else if (r >= arr.size()) l--;
            else if (x - arr[l] <= arr[r] - x) l--;
            else r++;
        }
        return vector<int>(arr.begin() + l + 1, arr.begin() + r);
    }
};