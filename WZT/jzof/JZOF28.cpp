// 对称的二叉树

// 题目描述
// 请实现一个函数，用来判断一颗二叉树是不是对称的。
// 注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。

#include "stdafx.h"

class Solution {
public:
    bool jdg_core(TreeNode *p1, TreeNode *p2) {
        if (!p1 && !p2) return true;
        if (!p1 || !p2) return false;
        
        return p1->val == p2->val && jdg_core(p1->left, p2->right)
                            && jdg_core(p1->right, p2->left);
    }
    bool isSymmetrical(TreeNode* pRoot)
    {
        if (!pRoot) return true;
        return jdg_core(pRoot->left, pRoot->right);
    }

};