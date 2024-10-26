// leetcode #2903 找出满足差值条件的下标 I
// 双指针

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        vector<int> answer(2);
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                if(abs(i - j) >= indexDifference && abs(nums[i] - nums[j]) >= valueDifference) {
                    answer[0] = i;
                    answer[1] = j;
                    return answer;
                }
            }
        }
        return {-1, -1};
    }
};