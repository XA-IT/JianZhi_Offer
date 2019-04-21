// 栈的压入、弹出序列

// 题目描述
// 输入两个整数序列，第一个序列表示栈的压入顺序，
// 请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。

// 例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
// 但4,3,5,1,2就不可能是该压栈序列的弹出序列。
// （注意：这两个序列的长度是相等的）

#include "stdafx.h"

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        // 先看输出序列, 根据输出去在输入中实现, 实现失败则不是
        auto p1 = pushV.begin();
        auto p2 = popV.begin();
        stack<int> assist;
        bool res = false;
        while (p2 != popV.end()) {
            // 需要先将元素推进栈中再比较, 如果先比较再推进去容易计算混乱
            while (assist.empty() || assist.top() != *p2) {
                if (p1 == pushV.end())
                    break;
                assist.push(*p1);
                ++p1;
            }
            if (assist.top() != *p2) 
                break;
            assist.pop();
            ++p2;
            
        }
        if (assist.empty() && p2 == popV.end())
            res = true;
        return res;        
    }
};