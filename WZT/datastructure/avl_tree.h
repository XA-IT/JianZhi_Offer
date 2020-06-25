/*
    avl tree: �κνڵ�����������ĸ߶������Ϊһ��������Ҳ����Ϊ�߶�ƽ����

    - ����/����/ɾ����ƽ��������ӶȾ�ΪO(logn)
    - ���¶����������ƽ������
        - LL(����/ɾ��������, ���ڵ�left��left�ȸ���right��2), RR, LR, RL����
    - ʹ֮����ƽ��ķ���:
        - ����ת: �����ڵ���ת����right��leftλ��
        - ����ת(������ת��Ӧ); ������ת(�����Һ�, RL���), ������ת;

 */


#pragma once
#include "pch.h"
#include "stdafx.h"
#include <iomanip>

 /* �ڵ㶨�� */
template <class T>
class AvlTreeNode {
public:
    T key;                  //��ֵ
    int height;             //�߶�
    AvlTreeNode *left;
    AvlTreeNode *right;

    AvlTreeNode(T value, AvlTreeNode *l, AvlTreeNode *r) :
        key(value), left(l), right(r), height(0) {}
};

/* avl������ */
template <class T>
class AvlTree {
private:
    AvlTreeNode<T> *mRoot;
public: // ����ӿ�
    AvlTree();
    ~AvlTree();

    // ��ȡ�����߶�
    int height();
    // ��������������
    int max(int a, int b);

    // ����
    void preOrder() const;
    void inOrder() const;
    void postOrder() const;

    // ����
    AvlTreeNode<T>* search(T key);
    T maximum();
    T minimum();

    // ����
    void insert(T key);

    // ɾ��
    void remove(T key);

    // ��ӡ
    void print();

    // ɾ��������
    void destroy();

private: // ���ڽӿ�
    // ��ȡ���ĸ߶�
    int height(AvlTreeNode<T> *tree);
        
    //--------------------------------------------------
    // ����key�ڵ� �Լ� ����
    //--------------------------------------------------
    // ����keyֵ��Ӧ�Ľڵ�, ������ڵ�, key, ���ؽڵ�
    AvlTreeNode<T>* search(AvlTreeNode<T> *tree, T key) const;

    // ������С�ڵ�, ������ڵ�, ������С�ڵ�  
    AvlTreeNode<T>* minimum(AvlTreeNode<T> *tree) const;

    // �������ڵ�, ������ڵ�, �������ڵ�
    AvlTreeNode<T>* maximum(AvlTreeNode<T> *tree) const;

    // ����
    void preOrder(AvlTreeNode<T> *tree) const;
    void inOrder(AvlTreeNode<T> *tree) const;
    void postOrder(AvlTreeNode<T> *tree) const;

    //--------------------------------------------------
    // ��������ƽ������
    //--------------------------------------------------
    // LL: ��Ҫ����ת
    AvlTreeNode<T>* leftLeftRotation(AvlTreeNode<T> *k2);

    // RR: ��Ҫ�ҵ���ת ���Ϊ�µĸ����ұ߲���
    AvlTreeNode<T>* rightRightRotation(AvlTreeNode<T> *k1);

    // LR: ��Ҫ������ת, ����ƽ��������(RR��ת��Ӧ�ڵڶ��ε�R), 
    //     ���������(��Ӧ�ڵ�һ�ε�L)
    AvlTreeNode<T>* leftRightRotation(AvlTreeNode<T> *k3);

    // RL: 
    AvlTreeNode<T>* rightLeftRotation(AvlTreeNode<T> *k1);

    // ����, ������ڵ㼰key, ���ظ��ڵ�
    AvlTreeNode<T>* insert(AvlTreeNode<T> *&tree, T key);

    // ɾ��, ������ڵ㼰Ҫɾ���Ľڵ�, ���ظ��ڵ�
    AvlTreeNode<T>* remove(AvlTreeNode<T> *&tree, AvlTreeNode<T> *z);
       
    // ��ӡ
    void print(AvlTreeNode<T>* tree, T key, int direction);

    // ɾ��������
    void destroy(AvlTreeNode<T> *&tree);
};