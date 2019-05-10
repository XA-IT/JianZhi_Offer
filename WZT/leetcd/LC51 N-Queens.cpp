// The n-queens puzzle is the problem of placing n queens on an n×n chessboard 
// such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle.

// Each solution contains a distinct board configuration of the n-queens' placement, 
// where 'Q' and '.' both indicate a queen and an empty space respectively.

// Example:

// Input: 4
// Output: [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],

//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.


#include "stdafx.h"

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        //每一列为一个vector, 每一行都需不同, 
        //即一种 0~n-1 全排列
        //验证对角线元素不同
        vector<int> tmp;
        for (int i = 0; i < n; ++i) {
            tmp.push_back(i);
        }
        vector<vector<int>> res_nqueen, all_res;
        //全排列, 生成
        for (size_t i = 0; i < tmp.size(); ++i) {
            
        }
        permutation(all_res, tmp, 0);
        for (auto i = 0; i < all_res.size(); ++i) {
            for (auto j = 0; j < all_res[i].size(); ++j) {
                cout << all_res[i][j] << " ";
            }
            cout << endl;
        }
        return { };
    }
    
    void permutation(vector<vector<int>> &all_res, 
                     vector<int> tmp, size_t idx) {
        if (idx == tmp.size()) {
            all_res.push_back(tmp);
            return;
        }
        for (size_t i = idx; i < tmp.size(); ++i) {
            swap(tmp[i], tmp[idx]);
            permutation(all_res, tmp, idx + 1);
            swap(tmp[i], tmp[idx]);
        }
    }
    
    bool isNQueens(vector<int>& tmp, const int n) {
        return true;
    }
};

int main() {
    Solution totest;
    auto tmp = totest.solveNQueens(3);
    return 0;
}