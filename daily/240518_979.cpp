// leetcode #979 分金币
// 后序遍历
/*
每个结点都会给出当前结点值减1个的硬币，若当前是0的话，就给出 -1 个，其实就是要一个
每个结点可以给出的硬币的总个数就是左右子结点分别可以给出的个数加上当前结点值并减1
*/ 

#include <iostream>

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
    int distributeCoins(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }

    int helper(TreeNode* node, int& res) {
        if (!node) return 0;
        
        int left = helper(node->left, res);
        int right = helper(node->right, res);

        res += abs(left) + abs(right);

        return node->val + left + right - 1;
    }
};