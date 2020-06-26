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

// ���δ�ӡ������ȫ���ڵ��ֵ
void printListNode(ListNode *head)
{
    int count = 0;
    while (head)
    {
        cout << head->val << ", ";
        head = head->next;
        count++;
    }
    cout << "END" << endl
         << "nums: " << count << endl;
}

// �������鹹����������ͷ�ڵ�
ListNode *buildListFromVec(vector<int> &nums)
{
    int sz = nums.size();
    if (sz == 0)
        return NULL;
    ListNode *head = new ListNode(nums.front()), *prev = head, *cur = NULL;
    for (int i = 1; i < sz; i++) {
        cur = new ListNode(nums[i]);
        prev->next = cur;
        prev = prev->next;
    }
    return head;
}

// ��ǰ�������ӡ���нڵ��ֵ
void printPreorderBinTree(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<TreeNode *> st;
    TreeNode *tmp = NULL;
    st.push(root);
    int count = 0;
    while (st.empty() != true)
    {
        tmp = st.top();
        st.pop();
        cout << tmp->val << " -> ";
        count++;
        if (tmp->right)
        {
            st.push(tmp->right);
        }
        if (tmp->left)
        {
            st.push(tmp->left);
        }
    }
    cout << "END" << endl
         << "node nums:" << count << endl;
}

void printBFSBinTree(TreeNode *root)
{
    if (root == NULL)
        return;
    queue<TreeNode *> qu;
    qu.push(root);
    TreeNode *cur = NULL;
    int count = 0;

    while (qu.empty() == false)
    {
        cur = qu.front();
        qu.pop();
        cout << cur->val << " -> ";
        count++;
        if (cur->left)
            qu.push(cur->left);
        if (cur->right)
            qu.push(cur->right);
    }
    cout << "END" << endl
         << "node nums: " << count << endl;
}
// ���ݲ�����������鹹�������������ظ��ڵ�
// �սڵ�ֵΪ-2
TreeNode *buildTreeFromBFSVec(vector<int> &nums)
{
    int sz = nums.size();
    if (sz == 0)
    {
        return NULL;
    }
    TreeNode *root = new TreeNode(nums.front()), *cur = NULL;
    int depth = 1, idx = 0;
    queue<TreeNode *> qu;
    qu.push(root);
    while (qu.empty() != true)
    {
        cur = qu.front();
        qu.pop();
        if (++idx >= sz)
            break;
        if (nums[idx] != -2)
        {
            cur->left = new TreeNode(nums[idx]);
            qu.push(cur->left);
        }
        if (++idx >= sz)
            break;
        if (nums[idx] != -2)
        {
            cur->right = new TreeNode(nums[idx]);
            qu.push(cur->right);
        }
    }
    return root;
}

vector<vector<char>> transIntMatrix2Chars(vector<vector<int>> &nums)
{
    int row = nums.size();
    if (row < 1)
        return { };
    int col = nums[0].size();
    vector<vector<char>> chars(row, vector<char> (col, '0'));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            chars[i][j] += nums[i][j];
        }
    }
    return chars;
}

// ��ӡ���������
void printMatrix(vector<vector<int>>& nums)
{
    int row = nums.size();
    if (row < 1)
        return;
    int col = nums[0].size();
    cout << "The matrix is " << row << " * " << col << ":" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

void printMatrix(vector<vector<char>>& nums)
{
    int row = nums.size();
    if (row < 1)
        return;
    int col = nums[0].size();
    cout << "The matrix is " << row << " * " << col << ":" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
    return;
}