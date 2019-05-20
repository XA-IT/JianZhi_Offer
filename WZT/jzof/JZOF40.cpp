// 最小的K个数
// 题目描述
// 输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。


#include "stdafx.h"

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int beg = 0, end = input.size() - 1;
        int idx = partition(input, beg, end);
        while (idx != k - 1) {
            if (idx > k - 1) {
                end = idx - 1;
            } else {
                beg = idx + 1;
            }
            idx = partition(input, beg, end);
        }
        vector<int> res(input.begin(), input.begin() + k);
        return res;
    }
    // 使用partition函数
    int partition(vector<int> &nums, int beg, int end) {
        if (beg < 0 || end > nums.size() - 1 || nums.empty() || beg > end)
            return -1;
        int idx = end, small_idx = beg - 1;
        for (int i = 0; i < end; ++i) {
            if (nums[i] < nums[idx]) {
                ++small_idx;
                if (small_idx != i) {
                    swap(nums[i], nums[small_idx]);
                }
            }
        }
        ++small_idx;
        swap(nums[small_idx], nums[idx]);
        return small_idx;
    }
    // 使用最大堆或红黑树表示
    vector<int> GetLeastNumbers_Solution2(vector<int> input, int k) {
        if (input.empty() || k > input.size())
            return { };
        set<int, greater<int> > res;
        for (auto num_It = input.begin(); num_It != input.end(); ++num_It) {
            if (res.size() < k) {
                res.insert(*num_It);
            } else if (*res.begin() > *num_It) {
                res.erase(res.begin());
                res.insert(*num_It);
            }
        }
        vector<int> res_vec;
        for (auto set_It = res.begin(); set_It != res.end(); ++set_It) {
            res_vec.push_back(*set_It);
        }
        return res_vec;
    }
};

int main() {
    Solution totest;
    vector<int> test1 = {2, 1, 5, 6, 3, 7};
    vector<int> res = totest.GetLeastNumbers_Solution(test1, 3);
    return 0;
}