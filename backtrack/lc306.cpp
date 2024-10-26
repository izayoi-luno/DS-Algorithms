// leetcode #306. 累加数
// 回溯法 + 子串分割问题

/*
这道题类似于lc93、lc131、lc282

常规解法会超时，
而由于这道题只用判断bool，
所以可以采用暴力穷举法
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <map>
#include <numeric>
#include <set>

using namespace std;

// 超时解法
class Solution1 {
public:
    bool valid;
    int n;
    bool isAdditiveNumber(string num) {
        vector<long long> seq;
        valid = false;
        if (num.size() % 2 == 0) n = num.size() / 2;
        else n = num.size() / 2 + 1;
        backtrack(num, seq, 0);
        return valid;
    }

    void backtrack(string num, vector<long long>& seq, int idx) {
        if (valid) return;
        if (idx == num.size()) {
            if (isValid(seq)) valid = true;
            return;
        }
        long long curr = 0;
        for (int i = idx; i < num.size() && (i == idx || num[idx] != '0'); i++) {
            if (i - idx >= n) break;
            curr = curr * 10 + (num[i] - '0');
            seq.push_back(curr);
            backtrack(num, seq, i + 1);
            seq.pop_back();
        }
    }
    
    inline bool isValid(vector<long long> seq) {
        if (seq.size() < 3) return false;
        for (int i = 2; i < seq.size(); i++) {
            if (seq[i] == (seq[i - 1] + seq[i - 2])) continue;
            else return false;
        }
        return true;
    }
};

class Solution2 {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        for (int secondStart = 1; secondStart < n - 1; ++secondStart) {
            if (num[0] == '0' && secondStart != 1) {
                break;
            }
            for (int secondEnd = secondStart; secondEnd < n - 1; ++secondEnd) {
                if (num[secondStart] == '0' && secondStart != secondEnd) {
                    break;
                }
                if (valid(secondStart, secondEnd, num)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool valid(int secondStart, int secondEnd, string num) {
        int n = num.size();
        int firstStart = 0, firstEnd = secondStart - 1;
        while (secondEnd <= n - 1) {
            string third = stringAdd(num, firstStart, firstEnd, secondStart, secondEnd);
            int thirdStart = secondEnd + 1;
            int thirdEnd = secondEnd + third.size();
            if (thirdEnd >= n || !(num.substr(thirdStart, thirdEnd - thirdStart + 1) == third)) {
                break;
            }
            if (thirdEnd == n - 1) {
                return true;
            }
            firstStart = secondStart;
            firstEnd = secondEnd;
            secondStart = thirdStart;
            secondEnd = thirdEnd;
        }
        return false;
    }

    string stringAdd(string s, int firstStart, int firstEnd, int secondStart, int secondEnd) {
        string third;
        int carry = 0, cur = 0;
        while (firstEnd >= firstStart || secondEnd >= secondStart || carry != 0) {
            cur = carry;
            if (firstEnd >= firstStart) {
                cur += s[firstEnd] - '0';
                --firstEnd;
            }
            if (secondEnd >= secondStart) {
                cur += s[secondEnd] - '0';
                --secondEnd;
            }
            carry = cur / 10;
            cur %= 10;
            third.push_back(cur + '0');
        }
        reverse(third.begin(), third.end());
        return third;
    }
};