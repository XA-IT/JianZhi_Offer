// Given a linked list, swap every two adjacent nodes and return its head.

// You may not modify the values in the list's nodes, only nodes itself may be changed.

 

// Example:

// Given 1->2->3->4, you should return the list as 2->1->4->3.

#include "stdafx.h"

class Solution {
public:
    void swap(ListNode* p1, ListNode* p2, ListNode* prep1) {
        if (prep1)
            prep1->next = p2;
        p1->next = p2->next;
        p2->next = p1;

    }
    //这个方法好像有点蠢...但是时间复杂度并未受影响~
    ListNode* swapPairs(ListNode* head) {
        ListNode prehead(0), *p = &prehead, *prep1 = p, *p1 = p, *p2 = p;
        p->next = head;
        int count = 0;
        p2 = p2->next;
        if (!p2) return prehead.next;
        p2 = p2->next;
        p1 = p1->next;
        if (!p2) return prehead.next;
        swap(p1, p2, prep1);
        ListNode* tmp = p1;
        p1 = p2;
        p2 = tmp;
        //p2 走在前
        while (p1 != NULL && p2 != NULL) {
            count++;
            p2 = p2->next;
            p1 = p1->next;
            prep1 = prep1->next;
            if (!p2) break;
            if (count == 2) {
                swap(p1, p2, prep1);
                ListNode* tmp = p1;
                p1 = p2;
                p2 = tmp;
                count = 0;
            }
        }
        return prehead.next;
    }
    //讨论区的高级做法, 使用指向指针的指针进行交换
    ListNode* swapPairs2(ListNode* head) {
    ListNode **pp = &head, *a, *b;
    while ((a = *pp) && (b = a->next)) {
        a->next = b->next;
        b->next = a;
        *pp = b;
        pp = &(a->next);
    }
    return head;
}
};

ListNode* test1() {
    vector<int> tmp = {1, 2, 3};
    ListNode prehead(0), *p = &prehead;
    for (int i = 0; i < tmp.size(); i++) {
        p->next = new ListNode(tmp[i]);
        p = p->next;
    }
    return prehead.next;
}

int main() {
    Solution totest;
    auto tmp = test1();
    auto tmp2 = totest.swapPairs(tmp);
    return 0;
}