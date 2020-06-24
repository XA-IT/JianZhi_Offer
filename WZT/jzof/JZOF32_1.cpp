// 从上往下打印二叉树1

// 题目描述
// 从上往下打印出二叉树的每个节点，同层节点从左至右打印。

#include "stdafx.h"

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        deque<TreeNode *> nodes;
        if (!root) return { };
        vector<int> res;
        TreeNode *cur = root;
        while (true) {
            if (cur->left) 
                nodes.push_back(cur->left);
            if (cur->right)
                nodes.push_back(cur->right);
            res.push_back(cur->val);
            if (nodes.empty())
                break;
            cur = nodes.front();
            nodes.pop_front();
        }
        return res;
    }
};

