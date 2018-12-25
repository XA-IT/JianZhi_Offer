// 合并两个排序的链表
// 题目描述
// 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* p1Node = pHead1, * p2Node = pHead2;
        ListNode* tempNode = nullptr, * headNode = p1Node;
        if(p1Node == nullptr)
            return p2Node;
        if(p2Node == nullptr)
            return p1Node;
        while(p1Node->next != nullptr || p2Node->next != nullptr){
            if(p1Node->val <= p2Node->val){
                if(p1Node->next->val <= p2Node->val){
                    p1Node = p1Node->next;
                }
                else{
                    tempNode = p1Node->next;
                    p1Node->next = p2Node;
                    p1Node = tempNode;
                }
            }
            else{
                if(p1Node->val <= p2Node->next->val){
                    tempNode = p2Node->next;
                    p2Node->next = p1Node;
                    p2Node = tempNode;
                }
                else{
                    p2Node = p2Node->next;
                }
            }
        }
        if(p1Node->next == nullptr){
            p1Node->next = p2Node;
        }
        else
            p2Node->next = p1Node;
        return headNode;            
    }
};