// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

// k is a positive integer and is less than or equal to the length of the linked list. 
// If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

// Example:

// Given this linked list: 1->2->3->4->5

// For k = 2, you should return: 2->1->4->3->5

// For k = 3, you should return: 3->2->1->4->5

// Note:

// Only constant extra memory is allowed.
// You may not alter the values in the list's nodes, only nodes itself may be changed.
#include "stdafx.h"

class Solution {
public:
    ListNode* swap(ListNode* pfirst, ListNode* plast, int k) {
        if (!pfirst || !plast) return nullptr;
        ListNode *p1 = pfirst, *p2 = pfirst->next;
        ListNode *tmp = plast->next, *tmp2 = nullptr;
        p1->next = tmp;
        int count = 0;
        while (p2 != tmp) {
            tmp2 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = tmp2;
        }
        return plast;
    }
    //方法错误...
    ListNode* reverseKGroup1(ListNode* head, int k) {
        ListNode *pfirst = head, *plast = pfirst, *tmp = plast;
        int count = 1;
        bool isfirst = true;
        while (plast && pfirst) {        
            while (plast && count != k) {
                count++;
                plast = plast->next;
            }
            if (count == k) {
                tmp = plast->next;
                if (isfirst)
                    head = swap(pfirst, plast, k);
                pfirst = tmp;
                if (!pfirst) return head;
                plast = pfirst;
                count = 1;
            }
        }
        return head;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        ListNode prehead(-1), *preheader = &prehead;
        prehead.next = head;
            //*pfirst = head, *plast = pfirst, *tmp = plast;
        int count = 0;
        ListNode *cur = preheader, *nex, *pre = preheader;
        while (cur = cur->next) count++;
        while (count >= k) {
            cur = pre->next;
            nex = cur->next;
            for (int i = 1; i < k; i++) {
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            pre = cur;
            count -= k;
        }
        return prehead.next;
    }
};

ListNode* test1() {
    vector<int> tmp = {1, 2, 3, 4, 5};
    ListNode prehead(0), *p = &prehead;
    for (int i = 0; i < tmp.size(); i++) {
        p->next = new ListNode(tmp[i]);
        p = p->next;
    }
    return prehead.next;
}

int main() {
    Solution totest;
    auto test01 = test1();
    auto res = totest.reverseKGroup(test01, 2);
    return 0;
}