// 不知道是第多少题...
// 数组中的逆序对
// 题目描述
// 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
// 输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 
// 即输出P%1000000007
// 输入描述:
// 题目保证输入的数组中没有的相同的数字

// 数据范围：

// 	对于%50的数据,size<=10^4

// 	对于%75的数据,size<=10^5

// 	对于%100的数据,size<=2*10^5

// 示例1
// 输入
// 1,2,3,4,5,6,7,0
// 输出
// 7

#include "stdafx.h"

class Solution {
public:
    int InversePairs(vector<int> data) {
        if (data.empty())
            return 0;
        vector<int> tmp_data = data;
        int beg = 0, end = tmp_data.size() - 1;
        long long count = InversePairsCore(tmp_data, beg, end);
        return count % 1000000007;
    }
    
    long long InversePairsCore(vector<int> &data, int beg, int end) {
        long long res = 0;
        if (beg >= end || end >= data.size())
            return res;
        if (end - beg == 1) {
            if (data[beg] > data[end]) {
                ++res;
                swap(data[beg], data[end]);
            }
            return res;
        }
        //divide:
        int sz = end - beg + 1, mid = beg + 0.5 * sz;
        long long left = InversePairsCore(data, beg, mid);
        long long right = InversePairsCore(data, mid + 1, end);
        //merge:
        int le_idx = mid, ri_idx = end, cp_idx = sz - 1;
        vector<int> copy(sz);
        while(le_idx >= beg && ri_idx >= mid + 1) {
            if (data[le_idx] > data[ri_idx]) {
                res += ri_idx - mid;
                copy[cp_idx--] = data[le_idx--];
            } else {
                copy[cp_idx--] = data[ri_idx--];
            }
        }
        for (; le_idx >= beg; ){
            copy[cp_idx--] = data[le_idx--];
        }
        for (; ri_idx >= mid + 1;)
            copy[cp_idx--] = data[ri_idx--];
        for (size_t i = 0; i < copy.size(); ++i)
            data[beg + i] = copy[i];
        return left + right + res;
    }
};


int main() {
    Solution totest;
    vector<int> test1 = {1, 2, 3, 4, 0};
    long long res = totest.InversePairs(test1);
    cout << res << endl;
    return 0;
}