// leetcode #473. 火柴拼正方形
// 回溯法 + 分段问题

/*
这道题类似于lc93，lc306

分段问题，回溯中的遍历是总共的段数，如果遍历原数组会产生大量的重复遍历进而超时

* 布尔型的问题，或者说只要判断一个解满足条件就返回true的问题，用常规回溯会大量重复并导致超时
* 所以要将回溯函数改为布尔类型
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

class Solution {
public:
    vector<int> edges;
    int segLength;
    bool makesquare(vector<int>& matchsticks) {
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        int n = matchsticks.size();
        int sm = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sm % 4 != 0) return false;
        edges.assign(4, 0);
        return backtrack(0, matchsticks, edges, sm / 4);
    }

    bool backtrack(int index, vector<int> &matchsticks, vector<int> &edges, int len) {
        if (index == matchsticks.size()) {
            return true;
        }
        for (int i = 0; i < edges.size(); i++) {
            edges[i] += matchsticks[index];
            if (edges[i] <= len && backtrack(index + 1, matchsticks, edges, len)) {
                return true;
            }
            edges[i] -= matchsticks[index];
        }
        return false;
    }
};