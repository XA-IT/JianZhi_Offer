// 链表中倒数第k个结点
// FindKthToTail
// 题目描述
// 输入一个链表，输出该链表中倒数第k个结点。

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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    
        if(pListHead == nullptr || k<1)
            return nullptr;
        ListNode* NodetoReturn = pListHead;
        ListNode* pNext = pListHead->next;
        unsigned int step = 0;
        while(step < k-1 && pNext != nullptr){
            pNext = pNext->next;
            step++;        
        }
        if(step<k-1)
            return nullptr;
        
        while(pNext != nullptr){
            pNext = pNext->next;
            NodetoReturn = NodetoReturn->next;
        }
        return NodetoReturn;
    }
};
