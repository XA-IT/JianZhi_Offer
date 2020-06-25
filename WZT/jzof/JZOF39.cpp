// 数组中出现次数超过一半的数字

// 题目描述
// 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
// 例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
// 由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

#include "stdafx.h"

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty())
            return 0;
        int length = numbers.size(), mid = 0.5 * length;
        int beg = 0, end = length - 1;
        int idx = partition(numbers, beg, end);
        while (idx != mid) {
            if (idx > mid) {
                end = idx - 1;
            } else {
                beg = idx + 1;
            }
            idx = partition(numbers, beg, end);
        }
        int res = numbers[idx];
        if (checkvalid(numbers, res) == false)
            res = -1;
        return res;
    }
    // solution 2: 从前往后遍历数组, 结果为count>1的数
    int MoreThanHalfNum_Solution2(vector<int> numbers) {
        if (numbers.empty())
            return 0;
        int length = numbers.size(), cur = numbers[0], count = 1;
        for (int i = 1; i < length; ++i) {
            if (numbers[i] == cur) {
                ++count;
            } else {
                --count;
                if (count == 0) {
                    cur = numbers[i];
                    count = 1;
                }
            }
        }
        if (checkvalid(numbers, cur) == false) 
            cur = 0;
        return cur;
    }
    int partition(vector<int>& numbers, int beg, int end) {
        int idx = end;
        if (numbers.empty() || 
            beg > end || end > numbers.size() - 1 || beg < 0) {
            return -1;
        }
        int small_idx = beg - 1;
        swap(numbers[idx], numbers[end]);
        for (int i = beg; i < end; ++i) {
            if (numbers[i] < numbers[end]) {
                ++small_idx;
                if (small_idx != i)
                    swap(numbers[i], numbers[small_idx]);
            }
        }
        ++small_idx;
        swap(numbers[small_idx], numbers[end]);
        return small_idx;
    }
    bool checkvalid(vector<int>& nums, int mostnum) {
        if (nums.empty())
            return false;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == mostnum)
                count++;
        }
        return 2 * count > nums.size();
    }
};

// 超过数组长度一半, 则第n/2大的数必为所求