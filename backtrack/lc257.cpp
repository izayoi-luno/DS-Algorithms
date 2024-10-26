// leetcode #257. 二叉树的所有路径
// 回溯法 + 树

/*
*注意数据类型！！！
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
    vector<string> ans;
    string path;
    vector<string> binaryTreePaths(TreeNode* root) {  
        if (root == nullptr) return {};
        backtrack(root, to_string(root->val));
        return ans;
    }

    void backtrack(TreeNode* root, string path) {
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(path);
            return;
        }
        if (root->left != nullptr) {
            backtrack(root->left, path + "->" + to_string(root->left->val));  //* 这么写是为了规避麻烦的cpp字符串操作
        }
        if (root->right != nullptr) {
            backtrack(root->right, path + "->" + to_string(root->right->val));
        }
    }
};