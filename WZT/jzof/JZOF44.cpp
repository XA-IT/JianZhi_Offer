// jzof44: 
// 数字以012345678901011121314...的格式序列化到一个字符序列中, 
// 请写一个函数, 求任意第n位对应的数字


#include "stdafx.h"

int digit_at_index(int n) {
    if (n <= 0)
        return 0;
    n += 1;
    if (n <= 10)
        return n - 1;
    int diglen = 1, nums = 10, digmax = 10;
    while (n - nums > 0) {        
        n -= nums;
        ++diglen;
        nums = diglen * (digmax * 9);
        digmax *= 10;
    }
    
    //--diglen;
    digmax /= 10;
    
    int res_remain = n % diglen;
    int res_n = digmax + n / (diglen);
    if (res_remain == 0) {
        --res_n;
        return res_n % 10;
    } else {
        int tmp = 1;
        for (int i = 0; i < diglen - res_remain; ++i) {
            tmp *= 10;
        }
        res_n /= tmp;
        return res_n % 10;
    }    
}

int main() {    
    string tmp_str, test1;
    for (int i = 0; i < 30; ++i) {
        stringstream ss;
        ss << i;
        ss >> tmp_str;
        test1 += tmp_str;
    }
    int res = digit_at_index(24);
    cout << res << ", " << test1[24] << endl;
    return 0;
}