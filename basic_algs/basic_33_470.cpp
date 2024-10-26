//leetcode #470 用rand7()实现rand10()
// 利用区间特性求解

#include <iostream>
#include <random>
using namespace std;

int rand7() {
    // 使用 std::random_device 生成随机种子
    random_device rd;

    // 使用 std::mt19937 引擎，并将随机种子作为种子传递给它
    mt19937 gen(rd());

    // 使用 std::uniform_int_distribution 定义生成整数的范围
    uniform_int_distribution<> dis(1, 7); // 生成1到7之间的整数

    // 生成随机整数
    int randomNumber = dis(gen);
}

class Solution {
public:
    int rand10() {
        int temp = 40;
        while(temp >= 40) temp = (rand7() - 1) * 7 + rand7() - 1;
        return temp % 10 + 1;
    }
};