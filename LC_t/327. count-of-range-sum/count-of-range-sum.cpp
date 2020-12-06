// 327. 区间和的个数
// 给定一个整数数组 nums，返回区间和在 [lower, upper] 之间的个数，包含 lower 和 upper。
// 区间和 S(i, j) 表示在 nums 中，位置从 i 到 j 的元素之和，包含 i 和 j (i ≤ j)。

// 说明:
// 最直观的算法复杂度是 O(n2) ，请在此基础上优化你的算法。

// 示例:

// 输入: nums = [-2,5,-1], lower = -2, upper = 2,
// 输出: 3 
// 解释: 3个区间分别是: [0,0], [2,2], [0,2]，它们表示的和分别为: -2, -1, 2。

#include "../public_utils/public_utils.h"

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        int count = 0, firstPos = sz;
        vector<long long> tmpSum(sz + 1);
        for (int i = 1; i < sz + 1; i++) {
            tmpSum[i] = tmpSum[i - 1] + nums[i - 1];
        }
        // nums[i] = tmpSum[i + 1] - tmpSum[i];
        for (int i = 0; i < sz; i++) {
            if (nums[i] > 0) {
                firstPos = i;
                break;
            }
        }
        long long sum1 = 0;
        for (int i = 0; i < sz; i++) {
            for (int j = i; j < sz; j++) {
                sum1 = tmpSum[j + 1] - tmpSum[i];
                if (sum1 <= upper) {
                    if (sum1 >= lower)
                        count++;
                } else {
                    if (j >= firstPos)
                        break;
                }
            }
        }
        return count;
    }
};

int main() {
    vector<vector<int>> tests = {
        {-5, 1, 0},
        {(int)2147483647, (int)-2147483648, -1, 0}
    };
    vector<vector<int>> test2 = {
        {1, 0},
        {-1, 0}
    };
    Solution sol;
    for (int i = 1; i < tests.size(); i++) {
        int ret = sol.countRangeSum(tests[i], test2[i][0], test2[i][1]);
        cout << "test " << i << " res: " << ret << endl;
    }
    return 0;
}