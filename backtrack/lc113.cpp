// leetcode #113. 路径总和 II
// 回溯法 + 树

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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return {};
        vector<vector<int>> ans;
        vector<int> path;
        int step = root->val;
        path.push_back(root->val);
        backtrack(root, targetSum, step, ans, path);
        return ans;
    }

    void backtrack(TreeNode* root, int targetSum, int step, vector<vector<int>>& ans, vector<int>& path) {
        if (step == targetSum && root->left == nullptr && root->right == nullptr) {
            ans.push_back(path);
            return;
        }
        if (root->left != nullptr) {
            path.push_back(root->left->val);
            backtrack(root->left, targetSum, root->left->val + step, ans, path);
            path.pop_back();
        }
        if (root->right != nullptr) {
            path.push_back(root->right->val);
            backtrack(root->right, targetSum, root->right->val + step, ans, path);
            path.pop_back();
        }
    }
};