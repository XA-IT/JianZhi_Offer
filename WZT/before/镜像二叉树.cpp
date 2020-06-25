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
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void exchange_leaf(TreeNode *pNode){
        TreeNode *temp_ex = nullptr;
        temp_ex = pNode->right;
        pNode->right = pNode->left;
        pNode->left = temp_ex;
        temp_ex = nullptr;
        return;
    }
    void Mirror(TreeNode *pRoot) {
        if(pRoot == nullptr)
            return;
        TreeNode *temp = nullptr;
        if(pRoot->left != nullptr || pRoot->right != nullptr){
            exchange_leaf(pRoot);
            if(pRoot->left)
                Mirror(pRoot->left);
            if(pRoot->right)
                Mirror(pRoot->right);
        }
        else
            return;
    }
};