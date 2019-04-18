// 调整数组顺序使奇数位于偶数前面

// 题目描述
// 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
// 使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
// 并保证奇数和奇数，偶数和偶数之间的相对位置不变。

#include "stdafx.h"

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        for(int i = 0;i < array.size();i++){
            for(int j = array.size()-1; j>i;j--){
                if(array[j]%2==1&&array[j-1]%2==0)
                    swap(array[j],array[j-1]);
            }
        }
    }
};

// 冒泡法, 每次把最右边的奇数放在左边开始的连续奇数的末尾

int main() {
    Solution totest;
    vector<int> test1 = {2, 2, 2, 2, 1};
    totest.reOrderArray(test1);
    for (auto vec_it = test1.begin(); vec_it != test1.end(); ++vec_it) {
        cout << *vec_it << " ";
    }
    cout << endl;
    return 0;
}