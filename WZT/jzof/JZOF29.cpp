// 包含min函数的栈

// 题目描述
// 定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。

#include "stdafx.h"

class Solution {
public:
    stack<int> nums;
    stack<int> min_n;
    void push(int value) {
        if (nums.empty()) {
            min_n.push(value);
        } else {
            int min = value > nums.top()? nums.top() : value;
            min_n.push(min);
        }
        nums.push(value);
    }
    void pop() {
        nums.pop();
        min_n.pop();
    }
    int top() {
        return nums.top();
    }
    int min() {
        return min_n.top();
    }
};