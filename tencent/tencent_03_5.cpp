//leetcode #5 最长回文串
// 中心展开算法 初始中心索引在字符串中心 每次递归将中心索引向两边前进 函数内部根据这个索引展开求极限长度

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int begin = 0;
    int maxLength = 0;
    string longestPalindrome(string s) {
        int n = s.size();
        centerExpand(s, n / 2, 0); // 中心展开算法
        string result = s.substr(begin, maxLength); // 生成字符串截断
        return result;
    }
    void centerExpand(string& s, int centerIndex, int direction) {
        int n = s.size();
        int i = centerIndex - 1; // 向前展开
        int j = centerIndex + 1; // 向后展开
        // 判断重复'bbbbb'
        while(i >= 0 && s[i] == s[centerIndex]) i--;
        while(j < n && s[j] == s[centerIndex]) j++;
        // 记录i j的位置以便于下一次递归
        int x = i;
        int y = j;
        while(x >= 0 && y < n && s[x] == s[y]) {
            x--;
            y++;
        }
        // 判断是否是最长的回文数
        if(y - x - 1 > maxLength) {
            begin = x + 1; // 注意边界条件
            maxLength = y - x - 1;
        }
        // 递归求其他可能存在的回文数
        // 第一个判定条件是是否剩下的总长度会比当前最大值大 如果不是的话根本没有可能会更大
        if((i + 1) * 2 - 1 > maxLength && direction <= 0) centerExpand(s, i, -1); // 0, ...(i-1), i, (i+1), ...2i
        if((n - j) * 2 - 1 > maxLength && direction >= 0) centerExpand(s, j, 1); // (2j-n+1), ...(j-1), j, (j+1), ...(n-1)
    }
};