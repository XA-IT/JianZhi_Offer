/*
    avl tree: 任何节点的两个子树的高度最大差别为一，所以它也被称为高度平衡树

    - 查找/插入/删除的平均与最坏复杂度均为O(logn)
    - 导致二叉查找树不平衡的情况
        - LL(插入/删除操作后, 根节点left的left比根的right大2), RR, LR, RL四种
    - 使之重新平衡的方法:
        - 左旋转: 将根节点旋转到其right的left位置
        - 右旋转(与左旋转对应); 左右旋转(先左右后, RL情况), 右左旋转;

 */


#pragma once
#include "pch.h"
#include "stdafx.h"
#include <iomanip>

 /* 节点定义 */
template <class T>
class AvlTreeNode {
public:
    T key;                  //键值
    int height;             //高度
    AvlTreeNode *left;
    AvlTreeNode *right;

    AvlTreeNode(T value, AvlTreeNode *l, AvlTreeNode *r) :
        key(value), left(l), right(r), height(0) {}
};

/* avl树定义 */
template <class T>
class AvlTree {
private:
    AvlTreeNode<T> *mRoot;
public: // 对外接口
    AvlTree();
    ~AvlTree();

    // 获取本树高度
    int height();
    // 求两个数中最大的
    int max(int a, int b);

    // 遍历
    void preOrder() const;
    void inOrder() const;
    void postOrder() const;

    // 查找
    AvlTreeNode<T>* search(T key);
    T maximum();
    T minimum();

    // 插入
    void insert(T key);

    // 删除
    void remove(T key);

    // 打印
    void print();

    // 删除整棵树
    void destroy();

private: // 对内接口
    // 获取树的高度
    int height(AvlTreeNode<T> *tree);
        
    //--------------------------------------------------
    // 查找key节点 以及 遍历
    //--------------------------------------------------
    // 查找key值对应的节点, 输入根节点, key, 返回节点
    AvlTreeNode<T>* search(AvlTreeNode<T> *tree, T key) const;

    // 查找最小节点, 输入根节点, 返回最小节点  
    AvlTreeNode<T>* minimum(AvlTreeNode<T> *tree) const;

    // 查找最大节点, 输入根节点, 返回最大节点
    AvlTreeNode<T>* maximum(AvlTreeNode<T> *tree) const;

    // 遍历
    void preOrder(AvlTreeNode<T> *tree) const;
    void inOrder(AvlTreeNode<T> *tree) const;
    void postOrder(AvlTreeNode<T> *tree) const;

    //--------------------------------------------------
    // 四种重新平衡的情况
    //--------------------------------------------------
    // LL: 需要左旋转
    AvlTreeNode<T>* leftLeftRotation(AvlTreeNode<T> *k2);

    // RR: 需要右单旋转 理解为新的根从右边产生
    AvlTreeNode<T>* rightRightRotation(AvlTreeNode<T> *k1);

    // LR: 需要两次旋转, 首先平衡左子树(RR旋转对应于第二次的R), 
    //     随后是整体(对应于第一次的L)
    AvlTreeNode<T>* leftRightRotation(AvlTreeNode<T> *k3);

    // RL: 
    AvlTreeNode<T>* rightLeftRotation(AvlTreeNode<T> *k1);

    // 插入, 输入根节点及key, 返回根节点
    AvlTreeNode<T>* insert(AvlTreeNode<T> *&tree, T key);

    // 删除, 输入根节点及要删除的节点, 返回根节点
    AvlTreeNode<T>* remove(AvlTreeNode<T> *&tree, AvlTreeNode<T> *z);
       
    // 打印
    void print(AvlTreeNode<T>* tree, T key, int direction);

    // 删除整棵树
    void destroy(AvlTreeNode<T> *&tree);
};