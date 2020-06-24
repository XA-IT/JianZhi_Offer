//148. 排序链表
//在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

//示例 1:

//输入: 4->2->1->3
//输出: 1->2->3->4
//示例 2:

//输入: -1->5->3->4->0
//输出: -1->0->3->4->5

#include "stdafx.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* node1, int len1, ListNode* node2, int len2) {
        ListNode* prev = new ListNode(0);
        ListNode* cur = prev;
        int count1 = 0, count2 = 0;
        while (count1 < len1 && count2 < len2) {
            if (node1->val < node2->val) {
                cur->next = node1;
                node1 = node1->next;
                cur = cur->next;
                ++count1;
            }
            else {
                cur->next = node2;
                node2 = node2->next;
                cur = cur->next;
                ++count2;
            }
        }

        while (count1 < len1) {
            cur->next = node1;
            node1 = node1->next;
            cur = cur->next;
            ++count1;
        }

        while (count2 < len2) {
            cur->next = node2;
            node2 = node2->next;
            cur = cur->next;
            ++count2;
        }
        cur = prev->next;
        delete prev;
        return cur;
    }

    //return head
    ListNode* mergeSort(ListNode* head, int len) {
        ListNode* nex = head, * pnex = nex;
        int len2 = len / 2, len1 = len - len2;
        if (len1 == 0 || len2 == 0) return head;
        
        for (int i = 0; i < len1; i++) {
            pnex = nex;
            nex = nex->next;
        }
        pnex->next = NULL;
        ListNode* node1 = NULL, * node2 = NULL;
        node1 = mergeSort(head, len1);
        node2 = mergeSort(nex, len2);
        return merge(node1, len1, node2, len2);
    }

    ListNode* sortList(ListNode* head) {
        int len = 0;
        ListNode* cur = head;
        while (cur) {
            ++len;
            cur = cur->next;
        }
        if (len < 2) return head;
        return mergeSort(head, len);
    }
};

int main() {
    vector<int> te = { 4, 2, 1, 3 };
    ListNode* prev = new ListNode(0);
    ListNode* cur = prev;
    for (auto t_It = te.begin(); t_It != te.end(); t_It++) {
        cur->next = new ListNode(*t_It);
        cur = cur->next;
    }
    Solution so;
    ListNode* sorted = so.sortList(prev->next);
    sorted->printList(sorted);
    return 0;
}