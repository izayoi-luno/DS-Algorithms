// leetcod #881 救生艇
// 贪心 + 双指针

/*
贪心：
1. 每次取最重的一个人 这样需要的船最少
2. 取最轻的人和最重的人做同一条船 这样需要的船最少
3. 如果最轻的人和最重的人不能同时坐下 那么所有人都不能喝最重的人一起坐 这样最重的人单独做一条船
4. 如果可以就安排最轻的人和最重的人坐一起 并将这两个人从数组中剔除出去
5. 这样就把n个人的问题转化为了n-2的问题的答案+1
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int res = 0;
        sort(people.begin(), people.end());
        int light = 0, heavy = people.size() - 1;
        while(light <= heavy) {
            if(people[light] + people[heavy] > limit) heavy--;
            else {
                heavy--;
                light++;
            }
            res++;
        }
        return res;
    }
};