// leetcode #1043 分割数组最大和
// 一维dp - 不定状态转移

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n);

        for(int i = 0; i < n; i++) {
            int maxv = 0;
            int count = 0;
            dp[i] = 0;
            for(int j = i; j >= 0; j--) {
                if(arr[j] > maxv) maxv = arr[j];

                count++;
                if(count > k) break;
                if(j > 0) dp[i] = max(dp[i], dp[j - 1] + count * maxv);
                else dp[i] = max(dp[i], count * maxv);
            }
        }

        return dp[n-1];

    }
};

int main() {
    Solution sol;
    vector<int> arr = {1,15,7,9,2,5,10};
    int k = 3;

    int res = sol.maxSumAfterPartitioning(arr, k);

    cout << res << endl;

    return 0;
}