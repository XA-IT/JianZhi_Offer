// 二叉搜索树的后序遍历序列

// 题目描述
// 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
// 如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

#include "stdafx.h"

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty()) return false;
        // the last element is the root of the tree
        size_t last_ele = sequence.size() - 1;
        bool res = true;
        size_t firstbigger = 0;
        for (; firstbigger != last_ele; ++firstbigger) {
            if (sequence[firstbigger] > sequence[last_ele]) {
                break;
            }
        }
        size_t cur_ele = firstbigger;
        for (; cur_ele != last_ele; ++cur_ele) {
            if (sequence[cur_ele] < sequence[last_ele]) {
                return false;
            }
        }
        if (firstbigger > 0)
            res = res && VerifySquenceOfBST({sequence.begin(), sequence.begin() + firstbigger});
        if (cur_ele < last_ele)
            res = res && VerifySquenceOfBST({sequence.begin() + firstbigger, 
                                             sequence.begin() + last_ele - firstbigger});
        return res;
    }
};