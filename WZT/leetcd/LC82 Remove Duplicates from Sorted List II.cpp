// Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

// Example 1:

// Input: 1->2->3->3->4->4->5
// Output: 1->2->5
// Example 2:

// Input: 1->1->1->2->3
// Output: 2->3
#include "stdafx.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode prehead(0), *p = &prehead, 
                 *pre = p, *nex = p->next;
        p->next = head;
        p = p->next;
        nex = p->next;
        while (nex) {
            if (p->val == nex->val) {
                do {
                    //delete nodes
                    p->next = nex->next;
                    nex = p->next;
                } while (nex && p->val == nex->val);
                //delete p
                pre->next = p->next;                
                p = pre->next;
                if (!p) break;
                nex = p->next;
            } else {
                pre = p;
                p = nex;
                nex = nex->next;
            }
        }
        return prehead.next;
    }
};