// Given a linked list, rotate the list to the right by k places, where k is non-negative.

// Example 1:

// Input: 1->2->3->4->5->NULL, k = 2
// Output: 4->5->1->2->3->NULL
// Explanation:
// rotate 1 steps to the right: 5->1->2->3->4->NULL
// rotate 2 steps to the right: 4->5->1->2->3->NULL
// Example 2:

// Input: 0->1->2->NULL, k = 4
// Output: 2->0->1->NULL
// Explanation:
// rotate 1 steps to the right: 2->0->1->NULL
// rotate 2 steps to the right: 1->2->0->NULL
// rotate 3 steps to the right: 0->1->2->NULL
// rotate 4 steps to the right: 2->0->1->NULL

#include "stdafx.h"

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
		if (k == 0 || !head) return head;
		ListNode preHead(0), *p1 = &preHead;
		p1->next = head;
		//count size
		int counter = -1;
		while (p1) {
			counter++;
			p1 = p1->next;
		}        
		p1 = &preHead;
		int posi = k % counter;
        if (posi == 0) return head;
		ListNode *p2 = head, *p3 = head, *tmp = head;
		counter = 0;
		while (p3 && counter != posi) {
			++counter;
			p3 = p3->next;
		}
		while (p3) {
			p3 = p3->next;
			p2 = p2->next;
			p1 = p1->next;
		}
		p1->next = NULL;
		preHead.next = p2;
		while (p2->next != p3) {
			p2 = p2->next;
		}
		p2->next = tmp;
		return preHead.next;
	}
};