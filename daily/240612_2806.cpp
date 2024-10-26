// leetcode #2806. 取整购买后的账户余额
// 数学

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int n = purchaseAmount % 10;
        int roundedAmount = 0;
        if(n >= 5) roundedAmount = (purchaseAmount / 10) * 10 + 10;
        else roundedAmount = (purchaseAmount / 10) * 10;
        return 100 - roundedAmount;
    }
};