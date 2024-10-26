//leetcode #4 两数组的中位数
// 分治法-递归 双指针

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        // 考虑合并数组长度的奇偶
        // 奇数长度左右相同 而偶数长度左右不同
        // 但是这样的话index会向后移一位 所以后续处理的时候要记得减1
        int left = (m + n + 1) / 2;
        int right = (m + n + 2) / 2;

        return (getNum(nums1, 0, m - 1, nums2, 0, n - 1, left) + getNum(nums1, 0, m - 1, nums2, 0, n - 1, right)) * 0.5; // 保证结果是double
    }
    
    int getNum(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k) {
        // 由于递归调用 nums的长度与实际上检索的长度不同        
        int len1 = end1 - start1 + 1;
        int len2 = end2 - start2 + 1;
        // 默认处理len1 < len2 不符合就交换
        if(len1 > len2) return getNum(nums2, start2, end2, nums1, start1, end1, k);
        // 递归结束条件是当其中一个数组区间为0的时候
        if(len1 == 0) return nums2[start2 + k - 1]; // 返回第k个数 index是k-1
        // 特殊情况 两个数组长度是1-0 0-1 1-1的时候 left=1
        if(k == 1) return min(nums1[start1], nums2[start2]);
        // 开始双指针比较递归
        // 指针开始位置设置是为了不用再从头开始找
        int i = start1 + min(len1, k / 2) - 1; // 同样记得index减1
        int j = start2 + min(len2, k / 2) - 1;
        if(nums1[i] > nums2[j]) return getNum(nums1, start1, end1, nums2, j + 1, end2, k - (j - start2 + 1)); // 第k个数字由于区间不同实际上要减去区间以前的数字
        else return getNum(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1));

    }
};
