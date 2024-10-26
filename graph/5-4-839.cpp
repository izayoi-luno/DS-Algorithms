// leetcode #839. 相似字符串组
// 无向图连通分量
// 并查集

/*
和其他题比多一个判断是否相似的函数
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
    UnionFind(int m) {
        parent.resize(m);
        for (int i = 0; i < m; i++) {
            parent[i] = i;
        }
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
    int numSimilarGroups(vector<string>& strs) {
        int m = strs.size();
        int n = strs[0].size();
        UnionFind uf(m);
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                if(uf.find(i) == uf.find(j)) continue;
                if(check(strs[i], strs[j], n)) uf.unionSet(i, j);
            }
        }
        int res = 0;
        for (int i = 0; i < m; i++) {
            if(uf.find(i) == i) res++;
        }
        return res;
    }

    bool check(string& str1, string& str2, int len) {
        int diffCount = 0;
        for(int i = 0; i < len; i++) {
            if(str1[i] != str2[i]) {
                diffCount++;
                if(diffCount > 2) return false;
            }
        }
        return true;
    }
};