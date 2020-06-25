// 反转链表

// 题目描述
// 输入一个链表，反转链表后，输出新链表的表头。

#include "stdafx.h"

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == NULL) return NULL;
        ListNode *p0 = NULL, *p1 = pHead, *p2 = p1->next;
        while (p2) {
            p1->next = p0;
            p0 = p1;
            p1 = p2;
            p2 = p2->next;
        }
        p1->next = p0;
        return p1;
    }
};