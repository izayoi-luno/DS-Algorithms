//leetcode #9 回文数
// solution-1 转为字符串+中心展开
// solution-2 转为字符串+检查对位
// solution-3 不用转化字符串+用reverse数存储输入的值

#include <iostream>
#include <string>

using namespace std;

class Solution_1 {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false; // 负数不被认为是回文数
        std::string str = std::to_string(x);
        int n = str.size();
        int i, j = 0;
        if(n % 2 == 0) {
            i = n / 2 - 1;
            j = n / 2;
        } else {
            i = n / 2 - 1;
            j = n / 2 + 1;
        }
        // 注意循环边界条件
        while(i >= 0 && j < n && str[i] == str[j]) {
            i--;
            j++;
        }
        if(i < 0 && j == n) return true;
        return false;

    }
};

class Solution_2 {
public:
    bool isPalindrome(int x) {
        std::string str = std::to_string(x);
        int n = str.size();
        // 只用迭代到一半的长度就行了
        for(int i = 0; i < n / 2; i++){
            if(str[i] != str[n-1-i]) return false; // 检查对位 只要不对称就返回
        }
        return true;

    }
};

class Solution_3 {
public:
    bool isPalindrome(int x) {
        if(x == 0) return true;
        if(x < 0 || x % 10 == 0) return false;
        int rev = 0;
        // 注意循环条件 不用完全迭代整个数 也是只用迭代一半就可以进行检查
        while(x > rev) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        if(x == rev || x == rev / 10) return true;
        return false;
    }
};