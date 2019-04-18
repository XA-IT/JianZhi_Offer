// 表示数值的字符串

// 题目描述
// 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
// 例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
// 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。

#include "stdafx.h"

class Solution {
public:
    bool ispurenum(char** string) {
        const char *prestr = *string;
        while (**string != '\0' && **string <= '9' && **string >= '0') {
            ++(*string);
        }
        return *string  > prestr;
    }
    bool isSignedNum(char** string) {
        if (**string == '+' || **string == '-') {
            ++(*string);
        }
        return ispurenum(string);
    }
    bool isNumeric(char* string)
    {   
        if (string == nullptr) return false;        
        // 正确的模式: A[.B][e|EC] 或 .B[e|EC] 
        bool res = isSignedNum(&string);
        if (*string == '.') {
            ++string;
            res = ispurenum(&string) || res;
        }
        
        if (*string == 'e' || *string == 'E') {
            ++string;
            res = res && isSignedNum(&string);
        }
        return res && *string == '\0';

    }
};

int main() {
    Solution totest;
    char test1[] = "123.45e+6";
    cout << totest.isNumeric(test1) << endl;
    return 0;
}