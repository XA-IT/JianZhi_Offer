// 2
// 题目描述
// 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。

#include "stdafx.h"
class Solution2 {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        if (!pRoot) return { };
        vector<int> tmp;
        vector<vector<int> > res;
        deque<TreeNode*> nodes;
        TreeNode * cur = pRoot;
        //res.push_back({ cur });
        int cur_level_nodes = 1, nex_level_nodes = 0;
        while (true) {            
            if (cur->left) {
                nodes.push_back(cur->left);    
                ++nex_level_nodes;
            }                   
            if (cur->right) {
                nodes.push_back(cur->right);
                ++nex_level_nodes;
            }
            tmp.push_back(cur->val);
            --cur_level_nodes;
            if (cur_level_nodes == 0) {
                res.push_back(tmp);
                tmp.clear();
                cur_level_nodes = nex_level_nodes;
                nex_level_nodes = 0;
            }
            if (nodes.empty())
                break;
            cur = nodes.front();
            nodes.pop_front();
        }
        return res;
    }
};