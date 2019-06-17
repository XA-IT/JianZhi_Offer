// 数字在排序数组中出现的次数
// 题目描述
// 统计一个数字在排序数组中出现的次数。


#include "stdafx.h"

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int le = BinarySearch(data, k-0.5);
        int ri = BinarySearch(data, k+0.5);
        return ri - le;
    }
    int BinarySearch(vector<int> data, double k) {
        if (data.empty())
            return -1;
        int beg = 0, end = data.size() - 1, mid = 0.5 * end;
        while (beg <= end) {
            if (data[mid] > k)
                end = mid - 1;
            else if (data[mid] < k)
                beg = mid + 1;
            mid = 0.5 * (beg + end);
        }
        return beg;
    }
};