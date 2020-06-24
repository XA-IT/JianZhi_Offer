// 链表中环的入口结点
// 题目描述
// 给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* whetherlooped(ListNode * pHead){
        if(pHead == nullptr)
            return nullptr;
        ListNode* pNext = pHead->next;
        ListNode* p1Node = pHead, * p2Node = pHead;
        while(p1Node->next != nullptr)
        {
            //if(p1Node->next != nullptr)
            p1Node = p1Node->next;
                
            if(p1Node->next != nullptr)
                p1Node = p1Node->next;
            p2Node = p2Node->next;
            if(p1Node == p2Node){
                return p1Node;
            }
        }
        return nullptr;
    }
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode* p1Node = pHead, *p2Node = pHead;

        ListNode* meetnode = nullptr;
        meetnode = whetherlooped(pHead);
        if(meetnode == nullptr)
            return nullptr;
        p1Node = meetnode->next;
        p2Node = meetnode;
        int numinLoop = 1;
        while(p2Node != p1Node)
        {
            p2Node = p2Node->next;
            p1Node = p1Node->next->next;
            numinLoop++;
        }
        p1Node = pHead;
        p2Node = pHead;
        for(int i=0; i<numinLoop; i++){
            p2Node = p2Node->next;
        }
        while(p1Node != p2Node){
            p1Node = p1Node->next;
            p2Node = p2Node->next;
        }
        return p1Node;
    }
    
};