#pragma once

#include <algorithm>
#include <string>
//#include <__msvc_all_public_headers.hpp>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <unordered_map>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}

    void printList(ListNode* head) {
        while (head) {
            cout << head->val << ", " << endl;
            head = head->next;
        }
    }
};
 
