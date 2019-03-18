// Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

// For example, given the following triangle

// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

// Note:

// Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
#include "stdafx.h"

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //dfs, 遍历每一层的所有可能元素
        //dfs不可取, dp, down-top
        int depth = triangle.size();
        if (!depth) return 0;
        int max_num = triangle[depth - 1].size();
        vector<int> res_temp = triangle[depth - 1];
        for (int i = depth - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size() ; ++j) {
                res_temp[j] = min(res_temp[j], res_temp[j + 1]) + triangle[i][j];
            }
        }
        return res_temp[0];
    }
};

int main() {
    Solution totest;
    vector<vector<int> > test1 = {
        {2},
        {3, 4}, 
        {6, 5, 7}, 
        {4, 1, 8, 3}
    };
    cout << totest.minimumTotal(test1) << endl;
    system("pause");
    return 0;
}