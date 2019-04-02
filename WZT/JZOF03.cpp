// 3_1: 数组中重复的数字

// 题目描述
// 在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。
// 也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 
// 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
// *duplication 记录找出的任一重复的数字

#include "stdafx.h"

bool duplicate(int numbers[], int length, int *duplication) {
    if (numbers == nullptr || length <= 0)  return false;
    // 检验是否符合要求
    // 0~n-1暗示可以对应数组的下标
    for (size_t i = 0; i < length; ++i) {
        if (numbers[i] < 0 || numbers[i] >= length)  return false;
    }

    for (size_t j = 0; j < length; ++j) {
        while (numbers[j] != j) {
            int tmp = numbers[j];
            if (numbers[tmp] == tmp) {
                *duplication = tmp;
                return true;
            } 
            numbers[j] = numbers[tmp];
            numbers[tmp] = tmp;
        }
    }
    return false;
}

// 3_2: 在n+1长的数组中元素范围在1~n, 找出重复的任一数字

// 二分查找的变体
int countinrange(const int* numbers, int length, int beg, int mid) {
    int count = 0;
    if (!numbers) return 0;
    for (size_t i = 0; i < length; ++i) {
        if (numbers[i] >= beg && numbers[i] <= mid) {
            ++count;
        }
    }
    return count;
}
int getDuplication(const int* numbers, int length) {
    if (!numbers || !length) return 0;
    int beg = 1, end = length - 1, count = 0;
    while (beg != end) {
        int mid = 0.5 * (beg + end);
        count = countinrange(numbers, length, beg, mid);
        if (count > mid - beg + 1) {
            end = mid;
        } else {
            beg = mid;
        }
    }
    count = countinrange(numbers, length, beg, mid);
    if (count > 1) 
        return beg;
    return -1;
}