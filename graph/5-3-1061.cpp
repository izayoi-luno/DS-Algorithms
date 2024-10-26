// leetcode #1061. 按字典序排列最小的等效字符串
// 无向图连通分量
// 并查集

/*
无向图的并查集就是等价关系的划分的集合
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
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        UnionFind uf;
        for (int i = 0; i < s1.size(); i++) {
            int index1 = s1[i] - 'a';
            int index2 = s2[i] - 'a';
            if (uf.find(index1) < uf.find(index2)) uf.unionSet(uf.find(index2), uf.find(index1));
            else uf.unionSet(uf.find(index1), uf.find(index2));
        }
        string res;
        for (int i = 0; i < baseStr.size(); i++) {
            char c = 'a' + uf.find(baseStr[i] - 'a');
            res.push_back(c);
        }
        return res;
    }
};