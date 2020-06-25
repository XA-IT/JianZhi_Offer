// 反转链表
// 题目描述
// 输入一个链表，反转链表后，输出新链表的表头。
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* tempNode = nullptr, * pNode = pHead;
        if(pNode == nullptr)
            return nullptr;
        ListNode* pNext = pNode->next;
        if(pNext == nullptr)
            return pNode;
        pNode->next = nullptr;        
        //pNext->next = pNode;
        while(pNext->next != nullptr){
            tempNode = pNext->next;
            pNext->next = pNode;
            pNode = pNext;
            pNext = tempNode;
        }
        pNext->next = pNode;
        return pNext;
    }
};