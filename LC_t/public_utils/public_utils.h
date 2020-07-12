// #pragma once

#include "stdafx.h"

// 为便于输入测试用例并查看结果，增加了构造和打印链表节点的函数
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// 依次打印单链表全部节点的值
void printListNode(ListNode *head);
// 根据数组构建链表，返回头节点
ListNode *buildListFromVec(vector<int> &nums);

// 为便于输入测试用例并查看结果，增加了构造和打印二叉树节点的函数
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 按前序遍历打印二叉树所有节点的值
void printPreorderBinTree(TreeNode *root);
// 按层序遍历打印二叉树所有节点的值
void printBFSBinTree(TreeNode *root);
// 根据层序遍历的数组构建二叉树，返回根节点
// 空节点值为-2
TreeNode *buildTreeFromBFSVec(vector<int> &nums);

// 将int型的矩阵转换为char型的矩阵
vector<vector<char>> transIntMatrix2Chars(vector<vector<int>> &nums);
// 打印矩阵的内容
void printMatrix(vector<vector<int>>& nums);
void printMatrix(vector<vector<char>>& nums);



// ************************************************************
//     以下为函数实现
// ************************************************************
