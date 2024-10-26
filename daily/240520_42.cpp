// leetcode #42 接雨水
// 辅助数组->单调队列

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int result = 0;

        vector<int> LeftMax(n);
        vector<int> RightMax(n);

        LeftMax[0] = height[0];
        for(int i = 1; i < n - 1; i++) LeftMax[i] = max(LeftMax[i-1], height[i]);
        
        RightMax[n-1] = height[n-1];
        for(int i = n - 2; i > 0; i--) RightMax[i] = max(RightMax[i+1], height[i]);

        for(int i = 1; i < n - 1; i++) {
            int capacity = min(LeftMax[i], RightMax[i]) - height[i];
            result += capacity;
        }

        return result;
    }
};