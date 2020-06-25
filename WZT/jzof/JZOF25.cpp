// 合并两个排序的链表

// 题目描述
// 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

#include "stdafx.h"

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (!pHead1) return pHead2;
        if (!pHead2) return pHead1;
        ListNode *resHead = nullptr;
        if (pHead1->val < pHead2->val) {
            resHead = pHead1;
            resHead->next = Merge(pHead1->next, pHead2);
        } else {
            resHead = pHead2;
            resHead->next = Merge(pHead1, pHead2->next);
        }
        return resHead;
    }
};