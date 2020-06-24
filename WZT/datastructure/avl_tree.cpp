#include "pch.h"
#include "stdafx.h"

#include "avl_tree.h"


template<class T>
AvlTree<T>::AvlTree() : mRoot(NULL)
{
}

template<class T>
AvlTree<T>::~AvlTree()
{
    destroy(mRoot);
}

// 获取树的高度
template <class T> 
int AvlTree<T>::height() {
    return height(mRoot);
}

// 求两个数中最大的
template<class T>
int AvlTree<T>::max(int a, int b)
{
    return a > b ? a : b;
}
template<class T>
void AvlTree<T>::preOrder() const
{
    preOrder(mRoot);
    cout << endl;
}
template<class T>
void AvlTree<T>::inOrder() const
{
    inOrder(mRoot);
    cout << endl;
}
template<class T>
void AvlTree<T>::postOrder() const
{
    postOrder(mRoot);
    cout << endl;
}
// 查找
template<class T>
AvlTreeNode<T>* AvlTree<T>::search(T key) 
{
    return search(mRoot, key);
}
// 插入
template<class T>
void AvlTree<T>::insert(T key)
{
    insert(mRoot, key);
}
// 删除
template<class T>
void AvlTree<T>::remove(T key)
{
    AvlTreeNode<T> *tmp = search(mRoot, key);
    if (tmp)
        remove(mRoot, tmp);
}

template <class T>
void AvlTree<T>::print()
{
    if (mRoot != NULL)
        print(mRoot, mRoot->key, 0);
}
/*
 * 打印"二叉查找树"
 *
 * key        -- 节点的键值
 * direction  --  0，表示该节点是根节点;
 *               -1，表示该节点是它的父结点的左孩子;
 *                1，表示该节点是它的父结点的右孩子。
 */
template <class T>
void AvlTree<T>::print(AvlTreeNode<T>* tree, T key, int direction)
{
    if (tree != NULL)
    {
        if (direction == 0)    // tree是根节点
            cout << setw(2) << tree->key << " is root" << endl;
        else                // tree是分支节点
            cout << setw(2) << tree->key << " is " << setw(2) << key << "'s " 
                 << setw(12) << (direction == 1 ? "right child" : "left child") << endl;

        print(tree->left, tree->key, -1);
        print(tree->right, tree->key, 1);
    }
}

template<class T>
void AvlTree<T>::destroy()
{
    destroy(mRoot);
}

// 获取树的高度
template<class T>
int AvlTree<T>::height(AvlTreeNode<T>* tree)
{
    if (tree != NULL)
        return tree->height;
    return 0;
}
// 查找key值对应的节点, 输入根节点, key, 返回节点
template<class T>
AvlTreeNode<T>* AvlTree<T>::search(AvlTreeNode<T>* tree, T key) const
{
    if (NULL == tree || tree->key == key)
        return tree;

    if (tree->key > key)
        return search(tree->left, key);
    else
        return search(tree->right, key);    
}
// 查找最小节点, 输入根节点, 返回最小节点  
template<class T>
AvlTreeNode<T>* AvlTree<T>::minimum(AvlTreeNode<T>* tree) const
{
    if (NULL == tree)
        return NULL;

    while (tree->left) {
        tree = tree->left;
    }
    return tree;
}
template <class T>
T AvlTree<T>::minimum()
{
    AvlTreeNode<T> *p = minimum(mRoot);
    if (p != NULL)
        return p->key;

    return (T)NULL;
}
// 查找最大节点, 输入根节点, 返回最大节点
template<class T>
AvlTreeNode<T>* AvlTree<T>::maximum(AvlTreeNode<T>* tree) const
{
    if (NULL == tree)
        return NULL;
    while (tree->right) {
        tree = tree->right;
    }
    return tree;
}
template <class T>
T AvlTree<T>::maximum()
{
    AvlTreeNode<T> *p = maximum(mRoot);
    if (p != NULL)
        return p->key;

    return (T)NULL;
}

template<class T>
void AvlTree<T>::preOrder(AvlTreeNode<T>* tree) const
{
    if (NULL == tree)
        return;
    cout << tree->key << " ";    
    preOrder(tree->left);    
    preOrder(tree->right);
}

template<class T>
void AvlTree<T>::inOrder(AvlTreeNode<T>* tree) const
{
    if (tree) {
        inOrder(tree->left);
        cout << tree->key << " ";
        inOrder(tree->right);
    }    
}

template<class T>
void AvlTree<T>::postOrder(AvlTreeNode<T>* tree) const
{
    if (tree) {
        postOrder(tree->left);
        postOrder(tree->right);
        cout << tree->key << " ";
    }
}

/* 左旋:
   k2为原根节点, 通过左单旋转变为高度更大的左子树的根节点k1为新的根节点, 
   k1的right成为k2的left
   */
template<class T>
AvlTreeNode<T>* AvlTree<T>::leftLeftRotation(AvlTreeNode<T>* k2)
{
    AvlTreeNode<T> *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    /* 更新height */
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    return k1;
}

// RR: 需要右单旋转 理解为新的根从右边产生
template<class T>
AvlTreeNode<T>* AvlTree<T>::rightRightRotation(AvlTreeNode<T>* k1)
{
    AvlTreeNode<T> *k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;

    // 更新height
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k2->height = max(height(k2->right), k1->height) + 1;
    return k2;
}
/* k3为原根节点, 开始时k1为k3的left, k2为k1的right */
template<class T>
AvlTreeNode<T>* AvlTree<T>::leftRightRotation(AvlTreeNode<T>* k3)
{
    // 右单旋转
    k3->left = rightRightRotation(k3->left);
    // 左单旋转
    return leftLeftRotation(k3);
}
// LR: 需要两次旋转, 首先平衡左子树(RR旋转对应于第二次的R), 
//     随后是整体(对应于第一次的L)
template<class T>
AvlTreeNode<T>* AvlTree<T>::rightLeftRotation(AvlTreeNode<T>* k1)
{
    k1->right = leftLeftRotation(k1->right);

    return rightRightRotation(k1);
}

// 插入, 输入根节点及key, 返回根节点
template<class T>
AvlTreeNode<T>* AvlTree<T>::insert(AvlTreeNode<T>*& tree, T key)
{
    if (NULL == tree) {
        tree = new AvlTreeNode<T>(key, NULL, NULL);
        if (tree == NULL) {
            cout << "ERROR: create avltree node failed." << endl;
            return NULL;
        }
    }
    else if (tree->key > key) {
        // 比根小, 左边
        tree->left = insert(tree->left, key);
        // 平衡
        if (height(tree->left) - height(tree->right) > 1) {
            if (key < tree->left->key)
                tree = leftLeftRotation(tree);
            else
                tree = leftRightRotation(tree);
        }
    }
    else if (tree->key < key) {
        // right
        tree->right = insert(tree->right, key);

        // 平衡
        if (height(tree->right) - height(tree->left) > 1) {
            if (key > tree->right->key)
                tree = rightRightRotation(tree);
            else
                tree = rightLeftRotation(tree);
        }
    }
    else {
        cout << "ERROR: 不能添加相同节点!" << endl;
        return tree;
    }
    tree->height = max(height(tree->left), height(tree->right)) + 1;
    return tree;
}
// 删除, 输入根节点及要删除的节点, 返回根节点
template<class T>
AvlTreeNode<T>* AvlTree<T>::remove(AvlTreeNode<T>*& tree, AvlTreeNode<T>* z)
{
    // 入参检查
    if (NULL == tree || NULL == z)
        return NULL;

    if (z->key < tree->key) {
        tree->left = remove(tree->left, z);

        if (height(tree->right) - height(tree->left) > 1) {
            AvlTreeNode<T> *tmp = tree->right;
            if (height(tmp->left) > height(tmp->right))
                tree = rightLeftRotation(tree);
            else
                tree = rightRightRotation(tree);
        }
    }
    else if (z->key > tree->key) {
        tree->right = remove(tree->right, z);

        if (height(tree->left) - height(tree->right) > 1) {
            if (height(tree->left->left) > height(tree->left->right))
                tree = leftLeftRotation(tree);
            else
                tree = leftRightRotation(tree);
        }
    }
    else {
        // 删除tree节点
        /* 需要找到替换的节点, 将key赋给tree, 并删除替换的节点 */
        if (tree->left && tree->right) {
            if (height(tree->left) > height(tree->right)) {
                AvlTreeNode<T> *tmp = maximum(tree->left);
                tree->key = tmp->key;
                tree->left = remove(tree->left, tmp);
            }
            else {
                AvlTreeNode<T> *tmp = minimum(tree->right);
                tree->key = tmp->key;
                tree->right = remove(tree->right, tmp);
            }
        }
        else {
            AvlTreeNode<T> *tmp = tree;
            tree = tree->left ? tree->left : tree->right;
            delete tmp;
        }
    }
    return tree;
}

template<class T>
void AvlTree<T>::destroy(AvlTreeNode<T> *&tree)
{
    if (NULL == tree)
        return;
    if (tree->left)
        destroy(tree->left);
    if (tree->right)
        destroy(tree->right);
    delete tree;
}


/**
 * C 语言: AVL树TEST
 *
 * @author skywang
 * @date 2013/11/07
 */

static int arr[] = { 3,2,1,4,5,6,7,16,15,14,13,12,11,10,8,9 };
#define TBL_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) )

int main()
{
    int i, ilen;
    AvlTree<int>* tree = new AvlTree<int>();

    cout << "== 依次添加: ";
    ilen = TBL_SIZE(arr);
    for (i = 0; i < ilen; i++)
    {
        cout << arr[i] << " ";
        tree->insert(arr[i]);
    }

    cout << "\n== 前序遍历: ";
    tree->preOrder();

    cout << "\n== 中序遍历: ";
    tree->inOrder();

    cout << "\n== 后序遍历: ";
    tree->postOrder();
    cout << endl;

    cout << "== 高度: " << tree->height() << endl;
    cout << "== 最小值: " << tree->minimum() << endl;
    cout << "== 最大值: " << tree->maximum() << endl;
    cout << "== 树的详细信息: " << endl;
    tree->print();

    i = 8;
    cout << "\n== 删除根节点: " << i;
    tree->remove(i);
    i = 11;
    cout << "\n== 删除节点: " << i;
    tree->remove(i);

    cout << "\n== 高度: " << tree->height();
    cout << "\n== 中序遍历: ";
    tree->inOrder();
    cout << "\n== 树的详细信息: " << endl;
    tree->print();

    // 销毁二叉树
    tree->destroy();

    return 0;
}
