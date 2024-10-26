// leetcode #79. 单词搜索
// 回溯法 - 二维数组

/*
这道题是lc212题的简单版

二维数组/矩阵回溯比一般的回溯多一层循环
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
    bool isExist;
    vector<vector<int>> dirs;
    vector<vector<int>> visited;
    int m;
    int n;
    bool exist(vector<vector<char>>& board, string word) {
        this->m = board.size();
        this->n = board[0].size();
        string currWord;
        isExist = false;
        visited.resize(m, vector<int>(n, 0));
        dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                currWord.push_back(board[i][j]);
                visited[i][j] = 1;
                backtrack(board, word, currWord, i, j);
                if (isExist == true) return isExist;
                visited[i][j] = 0;
                currWord.pop_back();
            }
        }
        return isExist;
    }

    void backtrack(vector<vector<char>>& board, string& word, string& currWord, int x, int y) {
        if (currWord == word) {
            isExist = true;
            return;
        }
        if (currWord.size() >= word.size()) return;
        for (int i = 0; i < 4; i++) {
            int newX = x + dirs[i][0];
            int newY = y + dirs[i][1];
            if (newX >= 0 && newX < m && newY >= 0 && newY < n && !visited[newX][newY]) {
                currWord.push_back(board[newX][newY]);
                visited[newX][newY] = 1;
                backtrack(board, word, currWord, newX, newY);
                visited[newX][newY] = 0;
                currWord.pop_back();
            }
        }
    }
};