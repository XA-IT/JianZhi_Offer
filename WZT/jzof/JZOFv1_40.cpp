// 数组中只出现一次的数字
// 一个整型数组里除了两个数字之外，其他的数字都出现了两次。
// 请写程序找出这两个只出现一次的数字。

#include "stdafx.h"
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if (data.empty())
            return;
        int data_len = data.size(), res = data.front();
        for (int i = 1; i < data_len; ++i) {
            res ^= data[i];
        }
        // find 1st 1:
        int count = 0;
        while ((res & 1) == 0) {
            res >>= 1;
            ++count;
        }
        vector<int> tmp1, tmp2;
        for (int i = 0; i < data_len; ++i) {
            if (IsBit(data[i], count))
                tmp1.push_back(data[i]);
            else 
                tmp2.push_back(data[i]);
        }
        res = tmp1.front();
        for (int i = 1; i < tmp1.size(); ++i) {
            res ^= tmp1[i];
        }
        *num1 = res;
        res = tmp2.front();
        for (int i = 1; i < tmp2.size(); ++i) {
            res ^= tmp2[i];
        }
        *num2 = res;
    }
    bool IsBit(int num,int index) {
        num=num>>index;
        return (num&1);
    }
};
// 一个数字和自身异或结果为0，序列中出现两次的数字可以被消除