//leetcode #136 只出现一次的数字
// 传统方法-哈希表存储每个数出现的次数 k=数字 v=count
// 使用位运算-异或

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 使用异或的特性 所有数按位异或0都等于它自己 所有数和自己异或都为0 异或满足交换律和结合律
        int result = 0;
        for(int i = 0; i < nums.size(); i++) result = result ^ nums[i];
        return result;
    }
};