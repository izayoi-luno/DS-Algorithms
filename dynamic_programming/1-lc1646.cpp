// leetcode #1646 获取生成数组中的最大值
// 直接求解（模拟）：生成数组 求数组最值
// 题目描述自身就是一个dp的状态转移

#include <iostream>
#include <vector>

using namespace std;

class Solution1 {
public:
    int getMaximumGenerated(int n) {
        vector<int> nums(n + 1);
        nums[0] = 0;
        for(int i = 1; i <= n; i++) {
            if(i == 1) nums[1] = 1;
            else {
                if(i % 2 == 0) nums[i] = nums[i / 2];
                else nums[i] = nums[i / 2] + nums[i / 2 + 1]; 
            }
        }

        int max = nums[0];
        for(int i = 0; i <= n; i++) {
            if(nums[i] > max) max = nums[i];
        }

        return max;
    }
};

class Solution2 {
public:
    int getMaximumGenerated(int n) {
        vector<int> nums(220); // 注意数组越界问题
        nums[0] = 0;
        nums[1] = 1;
        for(int i = 0; i <= n; i++) {
            if(2 <= 2 * i && 2 * i <= n) nums[2 * i] = nums[i];
            if(2 <= 2 * i + 1 && 2 * i + 1 <= n) nums[2 * i + 1] = nums[i] + nums[i + 1];
        }

        int m = nums[0];
        // 只在前n+1的长度中遍历最大值
        for(int i = 0; i <= n; i++) {
            m = max(m, nums[i]);
        }

        return m;
    }
};