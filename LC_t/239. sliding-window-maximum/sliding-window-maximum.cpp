// 239. 滑动窗口最大值
// 给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

// 返回滑动窗口中的最大值。


// 进阶：

// 你能在线性时间复杂度内解决此题吗？


// 示例:

// 输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
// 输出: [3,3,5,5,6,7] 
// 解释: 

//   滑动窗口的位置                最大值
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3        3 1 -1 -3 5
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7

// 提示：
// 1 <= nums.length <= 10^5
// -10^4 <= nums[i] <= 10^4
// 1 <= k <= nums.length
// 通过次数58,254提交次数120,988

#include "../public_utils/public_utils.h"

class Solution {
private:
    deque<int> dq;
    // 通过构造一个双端队列，维持队列中的元素 1，在窗口范围内；2，大于等于nums[i]
    // 以后每次排在最前的元素即为窗口中的最大元素
    // 双端队列的调用时长较久
    void cleanDq(vector<int>& nums, int i, int k) {
        if (dq.empty() == false && dq.front() == i - k) {
            dq.pop_front();
        }
        while (dq.empty() == false && nums[i] > nums[dq.back()]) {
            dq.pop_back();
        }
    }
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int sz = nums.size();
        if (sz * k == 0) return { };
        if (k == 1) return nums;
        int i = 0, maxIdx = 0;
        vector<int> ret(sz - k + 1);
        for (; i < k; i++) {
            cleanDq(nums, i, k);
            dq.push_back(i);
            if (nums[dq.front()] > nums[maxIdx]) maxIdx = dq.front();
        }
        ret[0] = nums[maxIdx];
        for (; i < sz; i++) {
            cleanDq(nums, i, k);
            dq.push_back(i);
            ret[i - k + 1] = nums[dq.front()];
        }
        return ret;
    }
};

int main() {
    vector<pair<vector<int>, int>> tests = {
        {{1, 3, -1, -3, 5, 3, 6, 7}, 3}
    };
    vector<vector<int>> expects = {
        {3, 3, 5, 5, 6, 7}
    };
    Solution sol;
    for (pair<vector<int>, int> test : tests) {
        vector<int> ret = sol.maxSlidingWindow(test.first, test.second);
        for (int num : ret) {
            cout << num << " ";
        }
        cout << endl;
    }
    for (vector<int> expectVec : expects) {
        for (int num : expectVec) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}