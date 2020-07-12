// #pragma once

#include "stdafx.h"

// Ϊ������������������鿴����������˹���ʹ�ӡ����ڵ�ĺ���
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// ���δ�ӡ������ȫ���ڵ��ֵ
void printListNode(ListNode *head);
// �������鹹����������ͷ�ڵ�
ListNode *buildListFromVec(vector<int> &nums);

// Ϊ������������������鿴����������˹���ʹ�ӡ�������ڵ�ĺ���
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// ��ǰ�������ӡ���������нڵ��ֵ
void printPreorderBinTree(TreeNode *root);
// �����������ӡ���������нڵ��ֵ
void printBFSBinTree(TreeNode *root);
// ���ݲ�����������鹹�������������ظ��ڵ�
// �սڵ�ֵΪ-2
TreeNode *buildTreeFromBFSVec(vector<int> &nums);

// ��int�͵ľ���ת��Ϊchar�͵ľ���
vector<vector<char>> transIntMatrix2Chars(vector<vector<int>> &nums);
// ��ӡ���������
void printMatrix(vector<vector<int>>& nums);
void printMatrix(vector<vector<char>>& nums);



// ************************************************************
//     ����Ϊ����ʵ��
// ************************************************************
