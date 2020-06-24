// 整数中1出现的次数（从1到n整数中1出现的次数）

// 题目描述
// 求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
// 为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。
// ACMer希望你们帮帮他,并把问题更加普遍化,
// 可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。

#include "stdafx.h"

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        if (n <= 0) 
            return 0;
        stringstream ss;
        string num;
        ss << n;
        ss >> num;
        return NumsOf1_core(num);
    }
    int NumsOf1_core(string num) {
        if (num.empty() || num.front() <= '0' || num.front() > '9')
            return 0;
        if (num.size() == 1)
            return num[0] == '0' ? 0 : 1;
        stringstream ss;
        size_t num_len = num.size();
        int res = 0, tmp = 0;
        // 计算最高位的1的次数
        string num2(num.begin() + 1, num.end());
        if (num[0] == '1') {
            ss << num2;
            ss >> tmp;
            res += tmp + 1;
        } else {
            tmp = 1;
            for (size_t i = 0; i < num_len - 1; ++i) {
                tmp *= 10;
            }
            res += tmp;
        }
        // 计算其他位的1的次数
        tmp = num[0] - '0';
        tmp *= num_len - 1;
        for (size_t i = 0; i < num_len - 2; ++i) {
            tmp *= 10;
        }
        res += tmp;
        return res + NumsOf1_core(num2);
    }
};