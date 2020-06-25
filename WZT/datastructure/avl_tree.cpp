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

// ��ȡ���ĸ߶�
template <class T> 
int AvlTree<T>::height() {
    return height(mRoot);
}

// ��������������
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
// ����
template<class T>
AvlTreeNode<T>* AvlTree<T>::search(T key) 
{
    return search(mRoot, key);
}
// ����
template<class T>
void AvlTree<T>::insert(T key)
{
    insert(mRoot, key);
}
// ɾ��
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
 * ��ӡ"���������"
 *
 * key        -- �ڵ�ļ�ֵ
 * direction  --  0����ʾ�ýڵ��Ǹ��ڵ�;
 *               -1����ʾ�ýڵ������ĸ���������;
 *                1����ʾ�ýڵ������ĸ������Һ��ӡ�
 */
template <class T>
void AvlTree<T>::print(AvlTreeNode<T>* tree, T key, int direction)
{
    if (tree != NULL)
    {
        if (direction == 0)    // tree�Ǹ��ڵ�
            cout << setw(2) << tree->key << " is root" << endl;
        else                // tree�Ƿ�֧�ڵ�
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

// ��ȡ���ĸ߶�
template<class T>
int AvlTree<T>::height(AvlTreeNode<T>* tree)
{
    if (tree != NULL)
        return tree->height;
    return 0;
}
// ����keyֵ��Ӧ�Ľڵ�, ������ڵ�, key, ���ؽڵ�
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
// ������С�ڵ�, ������ڵ�, ������С�ڵ�  
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
// �������ڵ�, ������ڵ�, �������ڵ�
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

/* ����:
   k2Ϊԭ���ڵ�, ͨ������ת��Ϊ�߶ȸ�����������ĸ��ڵ�k1Ϊ�µĸ��ڵ�, 
   k1��right��Ϊk2��left
   */
template<class T>
AvlTreeNode<T>* AvlTree<T>::leftLeftRotation(AvlTreeNode<T>* k2)
{
    AvlTreeNode<T> *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    /* ����height */
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    return k1;
}

// RR: ��Ҫ�ҵ���ת ���Ϊ�µĸ����ұ߲���
template<class T>
AvlTreeNode<T>* AvlTree<T>::rightRightRotation(AvlTreeNode<T>* k1)
{
    AvlTreeNode<T> *k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;

    // ����height
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k2->height = max(height(k2->right), k1->height) + 1;
    return k2;
}
/* k3Ϊԭ���ڵ�, ��ʼʱk1Ϊk3��left, k2Ϊk1��right */
template<class T>
AvlTreeNode<T>* AvlTree<T>::leftRightRotation(AvlTreeNode<T>* k3)
{
    // �ҵ���ת
    k3->left = rightRightRotation(k3->left);
    // ����ת
    return leftLeftRotation(k3);
}
// LR: ��Ҫ������ת, ����ƽ��������(RR��ת��Ӧ�ڵڶ��ε�R), 
//     ���������(��Ӧ�ڵ�һ�ε�L)
template<class T>
AvlTreeNode<T>* AvlTree<T>::rightLeftRotation(AvlTreeNode<T>* k1)
{
    k1->right = leftLeftRotation(k1->right);

    return rightRightRotation(k1);
}

// ����, ������ڵ㼰key, ���ظ��ڵ�
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
        // �ȸ�С, ���
        tree->left = insert(tree->left, key);
        // ƽ��
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

        // ƽ��
        if (height(tree->right) - height(tree->left) > 1) {
            if (key > tree->right->key)
                tree = rightRightRotation(tree);
            else
                tree = rightLeftRotation(tree);
        }
    }
    else {
        cout << "ERROR: ���������ͬ�ڵ�!" << endl;
        return tree;
    }
    tree->height = max(height(tree->left), height(tree->right)) + 1;
    return tree;
}
// ɾ��, ������ڵ㼰Ҫɾ���Ľڵ�, ���ظ��ڵ�
template<class T>
AvlTreeNode<T>* AvlTree<T>::remove(AvlTreeNode<T>*& tree, AvlTreeNode<T>* z)
{
    // ��μ��
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
        // ɾ��tree�ڵ�
        /* ��Ҫ�ҵ��滻�Ľڵ�, ��key����tree, ��ɾ���滻�Ľڵ� */
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
 * C ����: AVL��TEST
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

    cout << "== �������: ";
    ilen = TBL_SIZE(arr);
    for (i = 0; i < ilen; i++)
    {
        cout << arr[i] << " ";
        tree->insert(arr[i]);
    }

    cout << "\n== ǰ�����: ";
    tree->preOrder();

    cout << "\n== �������: ";
    tree->inOrder();

    cout << "\n== �������: ";
    tree->postOrder();
    cout << endl;

    cout << "== �߶�: " << tree->height() << endl;
    cout << "== ��Сֵ: " << tree->minimum() << endl;
    cout << "== ���ֵ: " << tree->maximum() << endl;
    cout << "== ������ϸ��Ϣ: " << endl;
    tree->print();

    i = 8;
    cout << "\n== ɾ�����ڵ�: " << i;
    tree->remove(i);
    i = 11;
    cout << "\n== ɾ���ڵ�: " << i;
    tree->remove(i);

    cout << "\n== �߶�: " << tree->height();
    cout << "\n== �������: ";
    tree->inOrder();
    cout << "\n== ������ϸ��Ϣ: " << endl;
    tree->print();

    // ���ٶ�����
    tree->destroy();

    return 0;
}
