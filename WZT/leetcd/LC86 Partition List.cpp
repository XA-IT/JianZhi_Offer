// Given a linked list and a value x, partition it such that all nodes less than x 
// come before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes in each of the two partitions.

// Example:

// Input: head = 1->4->3->2->5->2, x = 3
// Output: 1->2->2->4->3->5

#include "stdafx.h"

class Solution {
public:
    bool isless(const ListNode* head, int x) {
        return head->val < x;
    }
    ListNode* partition(ListNode* head, int x) {
        if (!head) return head;
        ListNode preh1(0), preh2(0), *p1 = &preh1, *p2 = &preh2;
        ListNode *p = head;
        while (p) {
            if (p->val < x) {
                p1->next = p;
                p1 = p1->next;
            } else {
                p2->next = p;
                p2 = p2->next;
            }
            p = p->next;
        }
        p2->next = NULL;
        p1->next = preh2.next;
        return preh1.next;
    }
};