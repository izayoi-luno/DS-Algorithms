// leetcode #990. 等式方程的可满足性
// 无向图连通分量
// 并查集

/*
使用并查集而不是dfs：
既要判断任意两个节点是否在一个连通分量内
又要判断***是否不在
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

using namespace std;

class UnionFind {
private:
    vector<int> parent;
public:
    UnionFind() {
        parent.resize(26);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int index) {
        if(index == parent[index]) return index;
        parent[index] = find(parent[index]);
        return parent[index];
    }

    void unionSet(int index1, int index2) {
        parent[find(index1)] = find(index2);
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf;
        for (auto & str : equations) {
            if (str[1] == '=') {
                int index1 = str[0] - 'a';
                int index2 = str[3] - 'a';
                uf.unionSet(index1, index2);
            }
        }
        for (auto & str : equations) {
            if (str[1] == '!') {
                int index1 = str[0] - 'a';
                int index2 = str[3] - 'a';
                if (uf.find(index1) == uf.find(index2)) return false;
            }
        }
        return true;
    }
};

