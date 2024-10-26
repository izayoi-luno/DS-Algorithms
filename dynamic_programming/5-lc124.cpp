// leetcode #124 二叉树中的最大路径和
// dp在树中的应用

/*
计算二叉树中的一个节点的最大贡献值，具体而言，就是在以该节点为根节点的子树中寻找以该节点为起点的一条路径，使得该路径上的节点值之和最大。
具体而言，该函数的计算如下。

空节点的最大贡献值等于 0。

非空节点的最大贡献值等于节点值与其子节点中的最大贡献值之和（对于叶节点而言，最大贡献值等于节点值）。
*/

// 所谓的贡献值 就是在递归返回向上的过程中对于每个节点选边时候参考的状态
// 换句话说 把递归向上的过程看成动态规划的状态转移 那么对于每层节点而言 他的路径只能是从他的两个子节点中选一个 所以说节点的 “贡献” 就代表值最大的那条路
// 因为虽然 这个节点的路径可以从他的子节点经过他到他的另一个子节点 但是对于上层的节点而言 经过他的路径只能是他和他的其中某一条子树
// 因此 用maxGain返回最大贡献 给上层节点做状态转移 而用maxSum保存对于这个节点而言的最大路径和 即左右节点的贡献和自己加起来

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
    int maxSum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }

    int maxGain(TreeNode* root) {
        if(root == nullptr) return 0;

        // 递归计算左右子节点的最大贡献值
        // 只有在最大贡献值大于 0 时，才会选取对应子节点
        int left = max(maxGain(root->left), 0);
        int right = max(maxGain(root->right), 0);

        // 节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值
        int price = root->val + left + right;

        // 保存 + 更新过程中的最大值
        maxSum = max(maxSum, price);

        // 返回节点的最大贡献值
        return root->val + max(left, right);
    }
};