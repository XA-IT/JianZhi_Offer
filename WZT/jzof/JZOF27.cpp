// 二叉树的镜像

// 题目描述
// 操作给定的二叉树，将其变换为源二叉树的镜像。
// 输入描述:
// 二叉树的镜像定义：源二叉树 
//     	    8
//     	   /  \
//     	  6   10
//     	 / \  / \
//     	5  7 9 11
//     	镜像二叉树
//     	    8
//     	   /  \
//     	  10   6
//     	 / \  / \
//     	11 9 7  5

#include "stdafx.h"

class Solution {
public:
    void exchangechild(TreeNode *pR) {
        if (!pR || (!pR->left && !pR->right)) return;
        TreeNode * tmp = pR->left;
        pR->left = pR->right;
        pR->right = tmp;
    }
    void Mirror(TreeNode *pRoot) {
        if (!pRoot) return;
        stack<TreeNode *> nodes;
        while (true) {
            if (!pRoot) {
                if (nodes.empty())
                    break;
                pRoot = nodes.top();
                nodes.pop();
            }
            exchangechild(pRoot);
            if (pRoot->right)
                nodes.push(pRoot->right);
            pRoot = pRoot->left;
        }
    }
};