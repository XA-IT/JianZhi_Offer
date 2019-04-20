// 树的子结构

// 题目描述
// 输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

#include "stdafx.h"
class Solution {
public:    
    //backtracking
    bool isSameStruct(TreeNode *p1, TreeNode *p2) {
        if (!p2) return true;
        if (!p1) return false;
        bool res = false;
        if (p1->val == p2->val) {
            res = isSameStruct(p1->left, p2->left) 
                  && isSameStruct(p1->right, p2->right);
        } else {
            return false;
        }
        return res;
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (!pRoot2 || !pRoot1) return false;
        bool res = false;
        TreeNode* p0 = pRoot1;
        // 前序遍历
        stack<TreeNode *> stk;
        while (true) {            
            if (!p0) {
                if (stk.empty())
                    return false;
                p0 = stk.top();
                stk.pop();
            }
            if(res = res || isSameStruct(p0, pRoot2))
                return true;
            if (p0->right != nullptr)
                stk.push(p0->right);
            p0 = p0->left;
        }
        return res;
    }
};