// // 剪绳子
// 给你一根长度为n的绳子，请把绳子剪成m段（m , n ）都是正整数，（n>1&m>1）
// 每段绳子的长度为k[0],k[1],k[2],...,k[m]。请问k[0]k[1]k[2]...k[m]的最大值。
// 例如绳子是长度为8，我们把它剪成的长度分别为2,3,3的三段，此时得到的最大的乘积是18。
// 注意! m并非给定值!!
#include "stdafx.h"

// 
int maxProductAfterCounting1(int length) {
    if (length < 2) 
        return 0;
    if (length == 2) 
        return 1;
    if (length == 3)
        return 2;
    
    int *products = new int[length + 1];
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;
    int max = 0;
    for (int i = 4; i <= length; ++i) {
        max = 0;
        for (int j = 1; j <= 0.5 * i; ++j) {
            int tmp = products[j] * products[i - j];
            if (max < tmp)
                max = tmp;
            products[i] = max;
        }
    }
    max = products[length];
    delete [] products;
    return max;
}

int main() {
    int res = maxProductAfterCounting1(8);
    return 0;
}