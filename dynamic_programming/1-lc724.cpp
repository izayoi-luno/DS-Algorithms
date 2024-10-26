// leetcode #724 寻找数组的中心下标
// 一维dp - 前缀和

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n);

        // 前缀和的求法
        for(int i = 0; i < n; i++) {
            sum[i] = nums[i];
            if(i) sum[i] += sum[i - 1];
        }

        if(sum[n - 1] == sum[0]) return 0;

        // 利用前缀和比较某点的左右两端的和
        for(int i = 1; i < n; i++) {
            if(sum[i - 1] == sum[n - 1] - sum[i]) return i;
        }

        return -1;
    }
};