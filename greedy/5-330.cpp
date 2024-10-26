// leetcode #330. 按要求补齐数组
// 贪心

/*
核心：对于正整数 x，如果区间 [1,x−1] 内的所有数字都已经被覆盖，且 x 在数组中，则区间 [1,2x−1] 内的所有数字也都被覆盖。

思路：每次找到未被数组 nums 覆盖的最小的整数 x，在数组中补充 x，然后寻找下一个未被覆盖的最小的整数，重复上述步骤直到区间 [1,n] 中的所有数字都被覆盖。

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patches = 0;  // 初始化要补的次数为0次  
        long long x = 1;  // 初始化x，此时区间为[0,0]
        int len = nums.size(), index = 0;  // 从第0个位置开始

        // 退出条件为x大于n，因为x总是代表[1, x-1]被覆盖到
        while (x <= n) {
            if (index < len && nums[index] <= x) {
                // 不需要添加数字，枚举nums每个数，合并更新覆盖范围
                x += nums[index];
                ++index;
            }
            else {
                // x无法被得到，需要添加数字。将x加入，覆盖范围变为2 * x - 1，更新 x *= 2
                x <<= 1;
                ++patches;
            }
        }
        return patches;
    }
};