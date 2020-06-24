// 105. Construct Binary Tree from Preorder and Inorder Traversal
// Given preorder and inorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

// For example, given

// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]
// Return the following binary tree:

//     3
//    / \
//   9  20
//     /  \
//    15   7
#include "stdafx.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //idx1指向根节点, idx2指向同样的值时一侧的树构建完成
        int idx = 0;
        return buildTree(preorder, inorder, idx, 0, preorder.size() - 1);
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int& idx, int start, int end) {
        if (idx >= preorder.size() || start > end) return NULL;
        auto pos = distance(inorder.begin(), find(inorder.begin()+start, inorder.begin() + end, preorder[idx]));
        TreeNode * treeroot = new TreeNode(preorder[idx]);
        idx++;
        treeroot->left = buildTree(preorder, inorder, idx, start, pos - 1);
        treeroot->right = buildTree(preorder, inorder, idx, pos + 1, end);
        return treeroot;
    }
};

int main () {
    Solution test0;
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode * tree = test0.buildTree(preorder, inorder);
    system("pause");
    return 0;    
}