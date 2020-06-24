// 二叉树中和为某一值的路径

// 题目描述
// 输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
// 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
// (注意: 在返回值的list中，数组长度大的数组靠前)

#include "stdafx.h"

class Solution {
public:
    void FindPath_core(vector<vector<int>> &res, vector<int> tmp,
                       TreeNode *cur, int target) {
        if (!cur || cur->val > target) return;
        target -= cur->val;
        tmp.push_back(cur->val);
        if (!cur->left && !cur->right) {
            if (target == 0) {
                res.push_back(tmp);
            }
            return;
        }
        if (cur->left) {
            FindPath_core(res, tmp, cur->left, target);
        }
        if (cur->right) {
            FindPath_core(res, tmp, cur->right, target);
        }
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        //dfs
        if (!root || root->val > expectNumber)
            return { };
        vector<vector<int>> res;
        vector<int> tmp;
        tmp.push_back(root->val);
        if (root->val == expectNumber) {
            res.push_back(tmp);
        }
        if (root->left) {
            FindPath_core(res, tmp, root->left, expectNumber - root->val);
        }
        if (root->right) {
            FindPath_core(res, tmp, root->right, expectNumber - root->val);
        }
        
        // bubble sort
        for (auto res_it1 = res.begin(); res_it1 != res.end(); ++res_it1) {
            for (auto res_it2 = res_it1; res_it2 != res.end(); ++res_it2) {
                if (res_it1->size() < res_it2->size())
                    swap(*res_it1, *res_it2);
            }
        }
        return res;
    }
};