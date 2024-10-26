// leetcode #95 不同的二叉搜索树 II
// dp在树中的应用

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(!n) return {};
        return backtracking(1, n);
    }
    
    vector<TreeNode*> backtracking(int start, int end) {
        if(start > end) return {nullptr};
        vector<TreeNode*> allTrees;
        for(int i = start; i <= end; i++) {
            vector<TreeNode*> leftTrees = backtracking(start, i - 1);
            vector<TreeNode*> rightTrees = backtracking(i + 1, end);

            for(auto& left : leftTrees) {
                for(auto& right : rightTrees) {
                    TreeNode* current = new TreeNode(i);
                    current->left = left;
                    current->right = right;
                    allTrees.emplace_back(current);
                }
            }
        }
        return allTrees;
    }

};