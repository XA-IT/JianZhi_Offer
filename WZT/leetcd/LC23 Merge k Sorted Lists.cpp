//#include "pch.h"
#include "stdafx.h"


int findMin(vector<ListNode*> & lists) {
	int res = 0;
	while (res < lists.size() && lists[res] == NULL) {
		res++;
	}
	for (int i = res + 1; i < lists.size(); i++) {
		if (lists[i] && lists[i]->val < lists[res]->val) {
			res = i;
		}
	}
	return res;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
	int length = lists.size();
	if (!length) return NULL;
	if (length == 1) return lists[0];
	vector<int> poi(length, 0);
	int cur_min = 0;
	ListNode prehead(0), *res = &prehead;
	while (true) {
		cur_min = findMin(lists);
		if (cur_min >= lists.size() || lists[cur_min] == NULL) break;
		res->next = new ListNode(lists[cur_min]->val);
		lists[cur_min] = lists[cur_min]->next;
		res = res->next;
	}
	return prehead.next;
}

vector<ListNode*> lc23test1() {
	vector<int> temp = { 1, 3, 4 };
	vector<int> temp2 = { 1, 2 };
	ListNode pre(0), *p = &pre;
	ListNode pre2(0), *p2 = &pre2;
	for (int i = 0; i < temp.size(); ++i) {
		p->next = new ListNode(temp[i]);
		p = p->next;
	}
	for (int i = 0; i < temp2.size(); ++i) {
		p2->next = new ListNode(temp2[i]);
		p2 = p2->next;
	}
	return { pre.next, pre2.next };
}

int main() {
	auto temp = lc23test1();
	auto temp2 = mergeKLists(temp);
	return 0;
}