/*
Graph-グラフ-图
*/
/*
This part is described detailedly in discrete mathematics
この部分は離散数学で詳しく説明される
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#define MAX_SIZE 100
using namespace std;
// 0. Basic way of defining graph
// This method with time complexity == O(v^2) : since the worst case is that when |V| == v, |E| == v(v-1) if it is directed graph and v(v-1)/2 if undirected
class Edge{
    string startVertex;
    string endVertex;
    int weight;
};

struct Edge_c{
    char* startVertex; // The edge is defined as the REFERENCES to the vertex list
    char* endVertex;
    int weight;
};
// using two lists to store the information of graph
string vertex_list[MAX_SIZE]; // !顶点列表
Edge edge_list[MAX_SIZE]; // !边列表

// 1. Define graph using Adjacent Matrix
// !邻接矩阵
/*
Adjacent Matrix is used as connection between vertices
For unweighted: connected -> A[i][j] == 1, otherwise == 0;
For weighted: A[i][j] == weight, otherwise == infinity;

Time complexity:
finding adjacent nodes: O(v);
finding two nodes are connected: O(1) (+ O(v)) <- can be avoided by using hash table
*/
/*
Drawbacks for this method: memory costy: only when the matrix is dense the efficiency would be high
The space complexity is O(v^2)
For most cases, the matrix would be sparse
*/

// 2. Define graph using Adjacent list
// !邻接表
struct Node{
    int val;
    int weight;
    Node* next;
};
Node* A[8];
/*
Time Complexity:
finding adjacent nodes: O(v); -> O(e) // e == an assumed maximum of edges
finding two nodes are connected: O(v) == O(e);
*/