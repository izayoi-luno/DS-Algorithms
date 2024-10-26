// leetcode #1342 到零的步数
// 递推

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfSteps(int num) {
        vector<int> f(1000001);
        f[0] = 0;
        for(int i = 1; i <= num; i++) {
            if(i % 2 == 1) f[i] = f[i-1] + 1;
            else f[i] = f[i/2] + 1;
        }
        return f[num];
    }
};