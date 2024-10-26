/*
Binary tree-二分木-二叉树
*/
/*
Concepts:
1. node-leaf | 2. parent-children-sibling-cousin | 3. height of a node - depth of a node (max height-max depth)
4. levels - maximum num of node in a tree with height h: N = 2^(no. of levels) - 1 = 2^(h+1) - 1 => h = (log2)(N+1) - 1
5. complete binary tree - perfect binary tree
5.1. for a complete binary tree height h = floor((log2)N) (take integer part)
6. condense tree - sparse tree
7. complexity: O(h) -> condense: O((log2)N) - sparse: O(N)
!7.1. that is to say we need to keep the height of the tree to be as small as possible -> keep the tree to be balanced 
7.2. the diff of height of left and right SUBtrees FOR ALL THE NODES is no more than k (mostly 1) (pay attention it is the height of subtrees, not containing itself)
8. height of an empty tree OR A SUBTREE: -1 -> height of an one-node tree is 0
8.1 diff of left and right = |h_left - h_right|
!9. binary search tree (BST) -> value of all the left subtree nodes < value of node < value of the right subtree nodes
*/
/*
implementation of binary search tree (BTS)
二分探索木の実装
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;
// 0. the tree node definition
struct BstNode{
    int val;
    BstNode* left;
    BstNode* right;    
};
// 0.1. Avoid repeatlt using the three lines to get a new node
BstNode* GetNewNode(int data){
    BstNode* newNode = new BstNode();
    newNode->val = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// 1. Insert a node 
BstNode* Insert(BstNode* root, int data){
    if(root == NULL){
        root = GetNewNode(data);
    }
    else if(data <= root->val){
        root->left = Insert(root->left, data);
    }
    else{
        root->right = Insert(root->right, data);
    }
    return root; // because it is a recursion, the root value for each time is DIFFERENT!
}
/*
Drawing stack-heap and recursion tree to understand the process
スタック⋮ヒープと再帰木を用いて過程を理解
通过画堆栈图和递归树来理解过程
*/
// 2. Search a node
bool Search(BstNode* root, int data){
    if(root == NULL) return false;
    else if(root->val == data) return true;
    else if(data <= root->val) return Search(root->left, data);
    else return Search(root->right, data); // pay attention to this pattern of using recursion
}
// 3. Find the minimum
int FindMin_Iter(BstNode* root){
    if(root == NULL){
        cout << "Error: the tree is empty" << endl;
        return -1;
    } // For any circumstances, check whether the tree is empty
    BstNode* current = root; // Since the root here is only a local variable, the current can be omitted
    while(current->left != NULL){
        current = current->left;
    }
    return current->val;
}
int FindMin_Recu(BstNode* root){
    if(root == NULL){
        cout << "Error: the tree is empty" << endl;
        return -1;
    }
    else if(root->left == NULL){
        return root->val; // If the left tree is empty, we already found the minimum
    }
    return FindMin_Recu(root->left); // Search in the left tree
}
// 4. Find the maximum - similar to the min
int FindMax_Iter(BstNode* root){
    if(root == NULL){
        cout << "Error: the tree is empty" << endl;
        return -1;
    } // For any circumstances, check whether the tree is empty
    while(root->right != NULL){
        root = root->right;
    }
    return root->val;
}
int FindMax_Recu(BstNode* root){
    if(root == NULL){
        cout << "Error: the tree is empty" << endl;
        return -1;
    }
    else if(root->right == NULL){
        return root->val; // If the left tree is empty, we already found the minimum
    }
    return FindMin_Recu(root->right); // Search in the left tree
}
// 5. Find the height of the tree
int FindHeight(BstNode* root){
    if(root == NULL) return -1;
    return max(FindHeight(root->left), FindHeight(root->right)) + 1;
}
/*
6.1.    Breadth-first: Tranversal by Level-order
        广度优先：层次遍历
        !Because of the link of each node is one direction, we use QUEUE to save the links to the children
*/
void LevelOrder(BstNode* root){
    if(root == NULL) return;
    queue<BstNode*> Q;
    Q.push(root);
    // the end condition:
    while(!Q.empty()){
        BstNode* current = Q.front();
        cout << current->val << " ";
        if(current->left != NULL) Q.push(current->left);
        if(current->right != NULL) Q.push(current->right);
        Q.pop();
    }
}
/*
6.2.    Depth-first: Tranversal by preoder inoder postoder
        深度优先：前序 中序 后序遍历
*/
void Preorder(BstNode* root){
    if(root == NULL) return; // exit condition
    cout << root->val << " "; // D: access/print first
    Preorder(root->left); // L: left
    Preorder(root->right); // R: right
}
void Inorder(BstNode* root){
    if(root == NULL) return;
    Inorder(root->left); // L
    cout << root->val << " "; // D
    Inorder(root->right); // R
}
void Postorder(BstNode* root){
    if(root == NULL) return;
    Postorder(root->left); // L
    Postorder(root->right); // R
    cout << root->val << " "; // D
}
// 7. Check whether it is a BST
bool IsSubtreeLesser(BstNode* root, int value){
    if(root == NULL) return true;
    if(root->val <= value
    && IsSubtreeLesser(root->left, value)
    && IsSubtreeLesser(root->right, value))
        return true;
    else
        return false;
}
bool IsSubtreeGreater(BstNode* root, int value){
    if(root == NULL) return true;
    if(root->val > value
    && IsSubtreeGreater(root->left, value)
    && IsSubtreeGreater(root->right, value))
        return true;
    else
        return false;
}
bool IsBST(BstNode* root){ // Not a good way since the small subtrees are checked for multiple times and the time-compexity will be extremely high
    if(root == NULL) return true;
    if(IsSubtreeLesser(root->left, root->val)
    && IsSubtreeGreater(root->right, root->val)
    && IsBST(root->left)
    && IsBST(root->right))
        return true;
    else
        return false;
}
// The better one:
bool IsBstUtil(BstNode* root, int min, int max){
    if(root == NULL) return true;
    if(root->val >= min
    && root->val < max
    && IsBstUtil(root->left, min, root->val)
    && IsBstUtil(root->right, root->val, max))
        return true;
    else
        return false;
}
bool IsBinarySearchTree(BstNode* root){
    return IsBstUtil(root, INT_MIN, INT_MAX);
}
// Another solution: using inorder tranversal (Omit)
// 8. Delete a node from BST
BstNode* Delete(BstNode* root, int value){ // !The root pointer might be modified so there must a return of the modified root pointer
    if(root == NULL) return root;
    else if(value < root->val) root->left = Delete(root->left, value); // Pay attention the condition MUST NOT have an equalization!!!
    else if(value > root->val) root->right = Delete(root->right, value); // These two stages using recursion to FIND the node
    else{ // We found you! This means value == root->val;
        // case 1: the node has no child
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL; // Pay attention this time the root would be a dangling pointer (悬空指针)
            return root;
        }
        // case 2: the node has only one child
        else if(root->left == NULL){
            BstNode* temp = root;
            root = root->right;
            delete temp;
            return root;
        }
        else if(root->right == NULL){
            BstNode* temp = root;
            root = root->left;
            delete temp;
            return root;
        }
        // case 3: the node has two children
        else{
            int temp = FindMin_Recu(root->right);
            root->val = temp;
            root->right = Delete(root->right, temp);
        }
    }
    return root;
}
// 9. Find the successor of the Inorder tranversal
BstNode* Find(BstNode* root, int data){
    if(root == NULL) return NULL;
    else if(root->val == data) return root;
    else if(data <= root->val) return root = Find(root->left, data);
    else return root = Find(root->right, data); 
}
BstNode* GetSuccessor(BstNode* root, int value){
    // Search the node - O(h)
    BstNode* current = Find(root, value);
    if(current == NULL) return NULL;
    // Case 1: Node has right subtree --->>> the successor is the min value of the right subtree
    if(current->right != NULL){
        BstNode* temp = current->right;
        while(temp->left != NULL) temp = temp->left;
        return temp;
    }
    // Case 2: Node has not right subtree --->>> Go back to the nearest ancestor of which the node is the left subtree
    else{
        BstNode* successor = NULL;
        BstNode* ancestor = root;
        while(current != ancestor){
            if(current->val < ancestor->val){
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else{
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}
int main(){
    BstNode* root = NULL; // Initialize an empty tree

}