// quick sort
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
// 分为两步: 
// 1. 选择一个数, 把比该数小的移到其左边, 比该数大的移到右边
//    - 注意, 记录该数的位置, 但在比较中不移动, 完成后将数插入
// 2. 对左边和右边的两个子序列进行同样的操作

int partition(vector<int>& nums, int beg, int end) {
    int imm = nums.size();
    if (beg < 0 || end >= nums.size() || end < beg || !nums.size()) 
        return -1;
    // 选择最右的数
    int idx = end;
    int small = beg - 1;
    for (size_t i = beg; i < end; ++i) {
        if (nums[i] < nums[idx]) {
            ++small;
            if (small != i)
                swap(nums[i], nums[small]);
        }
    }
    ++small;
    swap(nums[small], nums[end]);
    return small;
}

void quicksort(vector<int> & nums, int beg, int end) {
    if (!nums.size() || beg < 0 || end > nums.size() || end < beg) 
        return;
    if (end == beg) 
        return;
    int idx = partition(nums, beg, end);
    if (idx == -1) return;
    if (idx > beg)
        quicksort(nums, beg, idx - 1);
    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i] << endl;
    }
    if (idx < end)
        quicksort(nums, idx + 1, end);
    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i] << endl;
    }
}

vector<int> test01() {
    vector<int> nums = {1, 2, 3, 5, 2, 0};
    return nums;
}
int main() {
    vector<int> totest;
    totest = test01();
    quicksort(totest, 0, totest.size() - 1);
    for (size_t i = 0; i < totest.size(); ++i) {
        cout << totest[i] << endl;
    }
    return 0;
}