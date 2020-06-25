// 链表中环的入口结点

// 题目描述
// 给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。

#include "stdafx.h"

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        // count the nodes in loop
        bool hasloop = false;
        ListNode *p1 = pHead, *p2 = p1;
        while (p1 && p2 && p2->next) {
            if (p1 == p2) break;
            p2 = p2->next->next;
            p1 = p1->next;
        }
        if (p1 == NULL || p2 == NULL || p2->next == NULL)
            return NULL;
        // count beg
        int count = 0;
        do {
            p1 = p1->next;
            p2 = p2->next->next;
            ++count;
        } while (p1 != p2);
        p1 = pHead;
        p2 = pHead;
        while (count != 0) {
            --count;
            p2 = p2->next;
        }
        while (p2 != p1) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};