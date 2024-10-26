// leetcode #3115. 质数的最大距离
// 数论

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        vector<int> primes;
        for(int i = 0; i < nums.size(); i++) {
            if (isPrime(nums[i])) primes.push_back(i);
        }
        return primes.back() - primes[0];
    }

    bool isPrime(int num) {
        if (num == 1) return false;
        int factors = 0;
        for (int i = 2; i < num; i++) {
            if (!(num % i)) factors++; 
        }
        return !factors;
    }
};