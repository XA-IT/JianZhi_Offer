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

// 依次打印单链表全部节点的值
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

// 根据数组构建链表，返回头节点
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

// 按前序遍历打印所有节点的值
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
// 根据层序遍历的数组构建二叉树，返回根节点
// 空节点值为-2
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

// 打印矩阵的内容
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