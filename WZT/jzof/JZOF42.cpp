// 连续子数组的最大和

// 题目描述
// HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
// 今天测试组开完会后,他又发话了:在古老的一维模式识别中,
// 常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
// 但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
// 例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
// 给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)

#include "stdafx.h"

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        size_t arr_len = array.size();
        vector<int> sums(arr_len + 1);
        AddArrayInEveryElement(sums, array);
        int res = INT_MIN;
        for (size_t i = 0; i < arr_len; ++i) {
            for (size_t j = i; j < arr_len; ++j) {
                res = max(res, sums[j + 1] - sums[i]);
            }
        }
        return res;
    }
    void AddArrayInEveryElement(vector<int> &array, const vector<int> nums) {
        if (array.empty() || nums.size() != array.size() - 1)
            return;
        array[0] = 0;
        for (size_t i = 1; i < array.size(); ++i) {
            array[i] = array[i-1] + nums[i-1];
        }
    }
    // solution 2: 通过分析数组的规律/dp算法
    int FindGreatestSumOfSubArray2(vector<int> array) {
        size_t arr_len = array.size();
        int res = INT_MIN, tmp = 0;
        for (size_t i = 0; i < arr_len; ++i) {
            tmp += array[i];
            if (tmp < array[i])
                tmp = array[i];
            res = max(tmp, res);
        }
        return res;
    }
};