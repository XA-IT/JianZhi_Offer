// Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

// Note: The solution set must not contain duplicate subsets.

// Example:

// Input: [1,2,2]
// Output:
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]

#include "stdafx.h"

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res = { { } };
        int length = nums.size();
        if (!length) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < length; ) {
            int count = 0;      //重复的元素计数
            while (count + i < length && nums[i] == nums[i + count]) {
                ++ count;                
            }
            int cursize = res.size();
            for (int m = 0; m < cursize; ++ m) {
                vector<int> temp = res[m];
                for (int j = 0; j < count; ++j) {                                      
                    temp.push_back(nums[i]);                    
                    res.push_back(temp);
                }
            }
            i += count;
        }
        return res;
    }
};

vector<int> test0() {
    return {1, 2, 2};
}

vector<int> test1() {
    return {1, 1, 1, 1, 1, 2};
}
int main() {
    Solution totest;
    vector<int> test = test0();
    vector<vector<int>> res = totest.subsetsWithDup(test);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " " ;
        }
        cout << endl;
    }    
    system("pause");
    return 0;
}