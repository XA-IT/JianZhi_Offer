// 二叉搜索树与双向链表
// 题目描述
// 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
// 要求不能创建任何新的结点，只能调整树中结点指针的指向。
#include "stdafx.h"

class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (!pRootOfTree) return nullptr;
        TreeNode *last = nullptr, *root = pRootOfTree;
        Convert_core(pRootOfTree, &last);
        //root = last;
        while (root && root->left)
            root = root->left;
        return root;
    }
    
    void Convert_core(TreeNode* root, TreeNode** last_node) {
        if (!root) return;
        TreeNode *cur = root, *tmp = nullptr;
        if (cur->left)
            Convert_core(cur->left, last_node);
        cur->left = *last_node;
        if ((*last_node))
            (*last_node)->right = cur;
        
        *last_node = cur;
        if (cur->right)
            Convert_core(cur->right, last_node);
        
    }
};