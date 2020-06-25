// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

// (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

// Find the minimum element.

// The array may contain duplicates.

// Example 1:

// Input: [1,3,5]
// Output: 1
// Example 2:

// Input: [2,2,2,0,1]
// Output: 0
// Note:

// This is a follow up problem to Find Minimum in Rotated Sorted Array.
// Would allow duplicates affect the run-time complexity? How and why?
#include "premain.h"
//#include <vector>
//#include <stdio.h>
//#include <iostream>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int length = nums.size();
        if (!length) return 0;
        if (length == 1) return nums[0];
        int beg = 0, end = length - 1;        
        while (end > beg + 1 && nums[beg] == nums[end]) end--;
        if (nums[end] > nums[beg]) return nums[beg];
        while (end - beg > 1) {
            int mid = 0.5 * (beg + end);
            if (nums[beg] > nums[mid])
                end = mid;
            else 
                beg = mid;
        }
        return nums[end];
    }
};

int main() {
    Solution totest;
    vector<int> test0 = {5, 1, 5, 5, 5};
    cout << totest.findMin(test0) << endl;
    system("pause");
    return 0;
}