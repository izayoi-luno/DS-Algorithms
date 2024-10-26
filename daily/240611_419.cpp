// leetcode #419. 甲板上的战舰
// 1. dfs

/*
矩阵的dfs有个好处就是只用搜向前一列或一行
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int nums = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && board[i][j] == 'X') {
                    dfs(board, visited, i, j);
                    nums++;
                }
            }
        }
        return nums;
    }

    void dfs(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j) {
        visited[i][j] = 1;
        if(i < board.size() - 1) {
            if(!visited[i + 1][j] && board[i + 1][j] == 'X') dfs(board, visited, i + 1, j);
        }
        if(j < board[0].size() - 1) {
            if(!visited[i][j + 1] && board[i][j + 1] == 'X') dfs(board, visited, i, j + 1);
        }
        
    }
};