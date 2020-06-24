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
        vector<vector<string>> res;
        vector<string> tmp(n, string(n, '.'));
        size_t cur_row = 0;
        solveNQueens(res, tmp, cur_row, n);
        return res;
    }

    void solveNQueens(vector<vector<string>> &res, vector<string>& tmp, 
                      size_t cur_row, int& n) {
        if (cur_row == n) {
            res.push_back(tmp);
            return;
        }
        for (size_t col = 0; col != n; ++col) {
            if (isvalid(tmp, cur_row, col, n)) {
                tmp[cur_row][col] = 'Q';
                solveNQueens(res, tmp, cur_row + 1, n);
                tmp[cur_row][col] = '.';
            }
        }
    }

    bool isvalid(vector<string>& tmp, int cur_row, int col, int& n) {
        for (int i = 0; i != cur_row; ++i)
            if (tmp[i][col] == 'Q')
                return false;
        for (int i = cur_row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if (tmp[i][j] == 'Q')
                return false;
        for (int i = cur_row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            if (tmp[i][j] == 'Q')
                return false;
        return true;
    }
};

int main() {
    Solution totest;
    auto tmp = totest.solveNQueens(4);
    return 0;
}

// class Solution {
// public:
//     vector<vector<string>> solveNQueens(int n) {
//         //每一列为一个vector, 每一行都需不同, 
//         //即一种 0~n-1 全排列
//         //验证对角线元素不同
//         vector<int> tmp;
//         for (int i = 0; i < n; ++i) {
//             tmp.push_back(i);
//         }
//         vector<vector<int>> res_nqueen, all_res;
//         //全排列, 生成
//         permutation(all_res, tmp, 0);
//         // for (auto i = 0; i < all_res.size(); ++i) {
//         //     for (auto j = 0; j < all_res[i].size(); ++j) {
//         //         cout << all_res[i][j] << " ";
//         //     }
//         //     cout << endl;
//         // }
//         vector<vector<string>> res_str;
//         for (auto iter = all_res.begin(); iter != all_res.end(); ++iter) {
//             if (isNQueens(*iter, n)) {
//                 res_nqueen.push_back(*iter);
//                 res_str.push_back(convert_int2str_vec(*iter));
//             }
//         }
//         return res_str;
//     }
    
//     void permutation(vector<vector<int>> &all_res, 
//                      vector<int> tmp, size_t idx) {
//         if (idx == tmp.size()) {
//             all_res.push_back(tmp);
//             return;
//         }
//         for (size_t i = idx; i < tmp.size(); ++i) {
//             swap(tmp[i], tmp[idx]);
//             // 执行判断, 对于不满足要求的直接return
//             // if (isNQueens(tmp, i)) {
//                 permutation(all_res, tmp, idx + 1);
//             // }            
//             swap(tmp[i], tmp[idx]);
//         }
//     }
//     // 判断前idx - 1列是否满足n皇后, 即是否有在对角线的元素
//     bool isNQueens(const vector<int>& tmp, const size_t idx) {
//         for (size_t i = 0; i < idx; ++i) {
//             for (size_t j = i + 1; j < idx; ++j) {
//                 if (tmp[i] - tmp[j] == i - j
//                     || tmp[i] - tmp[j] == j - i) {
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }

//     vector<string> convert_int2str_vec(const vector<int>& vec_int) {
//         size_t len = vec_int.size();
//         vector<string> res(len, string(len, '.'));
//         for (size_t idx = 0; idx < len; ++idx) {
//             res[idx][vec_int[idx]] = 'Q';
//         }
//         return res;
//     }
// };
