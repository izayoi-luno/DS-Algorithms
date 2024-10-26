// leetcode #37. 解数独
// 回溯 + dfs

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool lin[9][9]; // lin[i][digit] 代表第i行的第digit个数是否写了
    bool col[9][9]; // col[j][digit] 代表第j列的第digit个数是否写了
    bool blk[3][3][9]; // blk[m][n][digit] 代表第m行第n列个格子的第digit个数是否写了 其中m = i / 3; n = j / 3;
    bool valid;
    vector<pair<int, int>> spc; // 储存没填入的位置 回溯时遍历这些位置
    
    void solveSudoku(vector<vector<char>>& board) {
        memset(lin, false, sizeof(lin));
        memset(col, false, sizeof(col));
        memset(blk, false, sizeof(blk));
        valid = false;

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') spc.emplace_back(i, j);
                else {
                    int digit = board[i][j] - '0' - 1;
                    lin[i][digit] = col[j][digit] = blk[i /3][j / 3][digit] = true;
                }
            }
        }
        // 以上是初始化

        backtracking(board, 0);
    }

    void backtracking(vector<vector<char>>& board, int pos) {
        if(pos == spc.size()) {
            valid = true;
            return;
        }

        auto [i, j] = spc[pos];
        for(int digit = 0; digit < 9 && !valid; digit++) {
            if(!lin[i][digit] && !col[j][digit] && !blk[i / 3][j / 3][digit]) {
                lin[i][digit] = col[j][digit] = blk[i /3][j / 3][digit] = true;
                board[i][j] = digit + '0' + 1;
                backtracking(board, pos + 1);
                lin[i][digit] = col[j][digit] = blk[i /3][j / 3][digit] = false;
            }
        }
        // 如果九个digit都不能填入 自动return
    }
};