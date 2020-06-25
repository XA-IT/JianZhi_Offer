// 104. ��������������
// ����һ�����������ҳ��������ȡ�

// �����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����

// ˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣

// ʾ����
// ���������� [3,9,20,null,null,15,7]��

//     3
//    / \
//   9  20
//     /  \
//    15   7
// �������������� 3 ��

#include "..\\public_utils.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        else
        {
            int l = maxDepth(root->left);
            int r = maxDepth(root->right);
            return l > r ? l + 1 : r + 1;
        }
    }
};

int main()
{
    vector<vector<int>> tests = {
        {3, 9, 20, -2, -2, 15, 7}
    };
    Solution sol;
    for (vector<int> te : tests) {
        TreeNode *root = buildTreeFromBFSVec(te);
        printBFSBinTree(root);
        cout << "result: " << sol.maxDepth(root) << endl;
    }
    return 0;
}
