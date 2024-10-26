// 并查集 disjoint set / union find set

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
public:
    vector<int> parent; // parent 数组保存每个节点的父节点

    // 初始化 每个节点的父节点是他自己 即初始化每个节点都是单独的连通分量的根节点
    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    // 合并两个连通分量 只需要把其中一个的祖先赋值成为另一个祖先的父节点
    void unionSet(int index1, int index2) {
        parent[find(index2)] = find(index1);
    }

    // 递归或者遍历查找每个节点的祖先/根节点
    int find(int index) {
        if (parent[index] != index) {
            parent[index] = find(parent[index]);
        }
        return parent[index];
    }
};