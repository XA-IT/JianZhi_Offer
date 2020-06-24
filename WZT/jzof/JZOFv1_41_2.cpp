// 和为S的两个数字
// 题目描述
// 输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，
// 如果有多对数字的和等于S，输出两个数的乘积最小的。
// 输出描述:
// 对应每个测试案例，输出两个数，小的先输出。

#include "stdafx.h"
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        if (array.empty())
            return { };
        vector<int> ret;
        int l_idx = 0, r_idx = 0, sumed = array[l_idx];
        while (r_idx < array.size()) {
            ++r_idx;
            sumed = array[l_idx] + array[r_idx];
            if (sumed > sum) { 
                ++l_idx;
                r_idx = l_idx + 1;
                continue;
            }
            if (sumed == sum)
                return {array[l_idx], array[r_idx]};
        }
        return ret;
    }

    vector<int> FindNumbersWithSum2(vector<int> array,int sum) {
        if (array.empty())
            return { };
        vector<int> ret;
        int l_idx = 0, r_idx = array.size() - 1, sumed = 0;
        while (l_idx < r_idx) {
            sumed = array[l_idx] + array[r_idx];
            if (sumed > sum) { 
                --r_idx;
            } else if (sumed < sum) {
                ++l_idx;
            } else
                return {array[l_idx], array[r_idx]};
        }
        return ret;
    }
};