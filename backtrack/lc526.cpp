// leetcode #526. 优美的排列
// 回溯法

/*
本题体现了回溯的一个优点：符合条件再继续向下递归搜索，否则回溯，从而节省时间

本题回溯的一个优化点：提前把每个位置的可能的情况写在二维数组perm里面，回溯的时候只需要遍历这个数组就行了
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

// 原版
class Solution1 {
public:
    vector<int> visited;
    int num;
    int countArrangement(int n) {
        visited.resize(n + 1);
        backtrack(1, n);
        return num;
    }

    void backtrack(int idx, int n) {
        if (idx == n + 1) {
            num++;
            return;
        }
        for (int i = 1; i <= n; i++) {
            if ((idx % i == 0 || i % idx == 0) && !visited[i]) {
                visited[i] = 1;
                backtrack(idx + 1, n);
                visited[i] = 0;
            }
        }
    }
};

// 优化版
class Solution2 {
public:
    vector<vector<int>> perm;
    vector<int> visited;
    int num;
    int countArrangement(int n) {
        perm.resize(n + 1);
        visited.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i % j == 0 || j % i == 0) perm[i].push_back(j);
            }
        }
        backtrack(1, n);
        return num;
    }

    void backtrack(int idx, int n) {
        if (idx == n + 1) {
            num++;
            return;
        }
        for (auto &x : perm[idx]) {
            if (!visited[x]) {
                visited[x] = 1;
                backtrack(idx + 1, n);
                visited[x] = 0;
            }
        }
    }
};