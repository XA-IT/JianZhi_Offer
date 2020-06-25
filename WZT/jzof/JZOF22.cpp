// 链表中倒数第k个结点

// 题目描述
// 输入一个链表，输出该链表中倒数第k个结点。

#include "stdafx.h"

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (pListHead == NULL) return NULL;
        unsigned int count = 0;
        ListNode *p1 = pListHead, *p2 = p1;
        while (count != k - 1) {
            if (p1->next == NULL)
                return NULL;
            p1 = p1->next;
            ++count;
        }
        while (p1->next != NULL) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }
};