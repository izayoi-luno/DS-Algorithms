// leetcode #189 轮转数组

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n) k = k % n;
        vector<int> helper(k);

        for(int i = 0; i < k; i++) helper[i] = nums[n - k + i];

        for(int i = n - 1; i >= k; i--) nums[i] = nums[i - k];

        for(int i = 0; i < k; i++) nums[i] = helper[i];
    }
};