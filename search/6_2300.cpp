// leetcode #2300. 咒语和药水的成功对数
// 二分查找 + O(n)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> pairs;
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        for (int i = 0; i < n; ++i) {
            long long pot = success / spells[i];
            int frc = success % spells[i];
            int pos = 0;
            if (!frc) pos = lower_bound(potions.begin(), potions.end(), pot) - potions.begin();
            else pos = lower_bound(potions.begin(), potions.end(), pot + 1) - potions.begin();
            pairs.push_back(m - pos);
        }
        return pairs;
    }
};