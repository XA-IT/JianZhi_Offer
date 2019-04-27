// 题目描述
// 请实现两个函数，分别用来序列化和反序列化二叉树

#include "stdafx.h"
// notes: 通过strcpy 与 strcat来处理char数组
class Solution {
public:
    char* Serialize(TreeNode *root) {    
        if(!root) return "$";
        string r = to_string(root->val);
        r.push_back(',');
        char *left = Serialize(root->left);
        char *right = Serialize(root->right);
        char *ret = new char[strlen(left) + strlen(right) + r.size()];
        strcpy(ret, r.c_str());
        strcat(ret, left);
        strcat(ret, right);
        return ret;
    }
    TreeNode* Deserialize(char *str) {
        TreeNode *res = nullptr;
        res = decode(str);        
        return res;
    }
    TreeNode* decode(char *&str) {
        if(*str=='$'){
            str++;
            return NULL;
        }
        int num = 0;
        while(*str != ',')
            num = num*10 + (*(str++)-'0');
        str++;
        TreeNode *root = new TreeNode(num);
        root->left = decode(str);
        root->right = decode(str);
        return root;
    }
};