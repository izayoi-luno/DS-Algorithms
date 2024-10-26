// leetcode #51. N 皇后
// 经典回溯法

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> chesserBoard(n, string(n, '.'));
        backtracking(n, 0, chesserBoard);
        return res;
    }

    void backtracking(int n, int row, vector<string>& chesserBoard) {
        if(row == n) {
            res.push_back(chesserBoard);
            return;
        }

        for(int col = 0; col < n; col++) {
            if(isValid(row, col, n, chesserBoard)) {
                chesserBoard[row][col] = 'Q';
                backtracking(n, row + 1, chesserBoard);
                chesserBoard[row][col] = '.'; // 执行回溯 把状态返还回去进行下一个同层级的枚举
            }
        }
    }

    bool isValid(int row, int col, int n, vector<string>& chesserBoard) {
        /* 
        
        只用检查列 45角 135角 同行不用检查因为每次每行只去一个格子 
        同时不用检查row col之后的格子因为还没有递归到
        
        */
       
        for(int i = 0; i < row; i++) {
            if(chesserBoard[i][col] == 'Q') return false;
        }

        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if(chesserBoard[i][j] == 'Q') return false;
        }

        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if(chesserBoard[i][j] == 'Q') return false;
        }

        return true;
    }
};