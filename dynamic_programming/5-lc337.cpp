// leetcode #337 打家劫舍III
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
    int rob(TreeNode* root) {
        vector<int> res = robTree(root);
        return max(res[0], res[1]); // 长度为2的数组 res[0]表示不偷root的最大金额 res[1]表示偷root的最大金额
    }

    vector<int> robTree(TreeNode* root) {
        /* 
        递归自顶向下但dp自底向上：采用二叉树的后序遍历：先左右子节点再自己
         */
        if(root == NULL) return vector<int> {0, 0};
        vector<int> left = robTree(root -> left);
        vector<int> right = robTree(root -> right);
        
        int val0 = max(left[0], left[1]) + max(right[0], right[1]); // 不再使用dp数组 用递归的每层保存dp状态：val0是不偷此节点的最大金额 val1是偷此节点的最大金额 
        int val1 = root -> val + left[0] + right[0];

        return vector<int> {val0, val1};
    }
};