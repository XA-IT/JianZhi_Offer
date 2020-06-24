// 按之字形顺序打印二叉树

// 题目描述
// 请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
// 第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。

#include "stdafx.h"
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        if (!pRoot) return { };
        vector<vector<int>> res;
        vector<int> tmp;
        stack<TreeNode*> leftd, rightd;
        TreeNode *cur = pRoot;
        bool isleft = true;    //本节点的子节点是从左开始存的吗
        while (true) {
            tmp.push_back(cur->val);
            if (isleft) {
                if (cur->left) {
                    leftd.push(cur->left);
                }
                if (cur->right) {
                    leftd.push(cur->right);
                }
            } else {
                if (cur->right) {
                    rightd.push(cur->right);
                }
                if (cur->left) {
                    rightd.push(cur->left);
                }
            }
            if (!isleft) {
                if (leftd.empty()) {
                    //从左向右的一行打完
                    res.push_back(tmp);
                    tmp.clear();
                    isleft = 1-isleft;
                    if (rightd.empty())
                        break;
                    cur = rightd.top();
                    rightd.pop();
                    continue;
                }
                cur = leftd.top();
                leftd.pop();
            }
            else {
                if (rightd.empty()) {
                    //从左向右的一行打完
                    res.push_back(tmp);
                    tmp.clear();
                    isleft = 1-isleft;
                    if (leftd.empty())
                        break;
                    cur = leftd.top();
                    leftd.pop();
                    continue;
                }
                cur = rightd.top();
                rightd.pop();
            }
        }
        return res;
    }    
};