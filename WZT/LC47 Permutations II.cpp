// Given a collection of numbers that might contain duplicates, return all possible unique permutations.

// Example:

// Input: [1,1,2]
// Output:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]

#include "stdafx.h"

class Solution {
public:
    void recursion_core(vector<int> nums, size_t beg, size_t len, vector<vector<int>> &res) {
        if (beg == len - 1) {
            res.push_back(nums);
            return;
        }
        for (size_t j = beg; j < len; ++j) {
            if (j != beg && nums[beg] == nums[j]) continue;
            swap(nums[beg], nums[j]);
            recursion_core(nums, beg + 1, len, res);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // 确保每次选出一个数，剩下的子数组也应各不相同
        // 找一个p1放在0，第二个p2放在1，
        size_t len = nums.size();
        if (!len) return { };
        if (len == 1) return {nums};
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        recursion_core(nums, 0, len, res);
        return res;
    }
};

// backtracking, 每次选出一个与之前不同的数, 保证剩下的数组成的数组仍然有序, 从而确保无重复子数组