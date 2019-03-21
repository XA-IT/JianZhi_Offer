// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

// (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

// Find the minimum element.

// You may assume no duplicate exists in the array.

// Example 1:

// Input: [3,4,5,1,2] 
// Output: 1
// Example 2:

// Input: [4,5,6,7,0,1,2]
// Output: 0

#include "stdafx.h"

class Solution {
public:
    int findMin(vector<int>& nums) {
        int length = nums.size();
        if (!length) return 0;
        if (length == 1 || nums[0] < nums.back()) return nums[0];
        int beg = 0, end = length - 1;
        while (end - beg > 1) {
            int mid = 0.5 * (end + beg);
            if (nums[beg] > nums[mid])
                end = mid;
            else
                beg = mid;
        }
        return nums[end];
    }
}
