#pragma once
#include "public_utils/public_utils.h"

class Solution_lc1958 {
    const int ROW_NUM = 8;
    int _rMove;
    int _cMove;
    char _color;
    char _recolor;
    static inline char getRev(char color) {
        return color == 'B' ? 'W' : 'B';
    }
    int getNextRow(const int row, const char direct) const {
        switch (direct) {
            case 'q':
            case 'e':
            case 'w':
                return (row - 1 >= 0) ? row - 1 : -1;
            case 'z':
            case 'c':
            case 's':
                return (row + 1 < ROW_NUM) ? row + 1 : -1;
            case 'a':
            case 'd':
                return row;
            default:
                return -1;
        }
    }
    int getNextCol(const int col, const char direct) const {
        switch (direct) {
            case 'q':
            case 'z':
            case 'a':
                return (col - 1 >= 0) ? col - 1 : -1;
            case 'e':
            case 'c':
            case 'd':
                return (col + 1 < ROW_NUM) ? col + 1 : -1;
            case 'w':
            case 's':
                return col;
            default:
                return -1;
        }
    }
    int getDistance(int row, int col) {
        return max(abs(row - _rMove) + 1, abs(col - _cMove) + 1);
    }
    bool checkOneDirect(vector<vector<char>> &board, char direct) {
        int i = getNextRow(_rMove, direct);
        int j = getNextCol(_cMove, direct);
        while (i != -1 && j != -1) {
            if (board[i][j] == _recolor) {
                i = getNextRow(i, direct);
                j = getNextCol(j, direct);
            } else if (board[i][j] == _color) {
                int tmpi = getNextRow(i, direct);
                int tmpj = getNextCol(j, direct);
                int tmpdis = getDistance(i, j);
                if (tmpdis > 2 /* && (tmpi == -1 || tmpj == -1 || board[tmpi][tmpj] == '.') */) {
                    return true;
                } else {
                    return false;
                }
            } else if (board[i][j] == '.') {
                return false;
            }
        }
        return false;
    }
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        vector<vector<char>> tmp;
        _recolor = getRev(color);
        _color = color;
        _rMove = rMove;
        _cMove = cMove;
        string direct = "wsadqezc";
        for (int i = 0; i < direct.size(); i++) {
            if (checkOneDirect(board, direct[i])) {
                return true;
            }
        }
        return false;
    }
};

inline void testLc1958()
{
    vector<vector<char>> board = {
        // {'.','.','.','B','.','.','.','.'},
        // {'.','.','.','W','.','.','.','.'},
        // {'.','.','.','W','.','.','.','.'},
        // {'.','.','.','W','.','.','.','.'},
        // {'W','B','B','.','W','W','W','B'},
        // {'.','.','.','B','.','.','.','.'},
        // {'.','.','.','B','.','.','.','.'},
        // {'.','.','.','W','.','.','.','.'}
        {'B','B','.','.','B','W','W','.'},
        {'.','W','W','.','B','W','B','B'},
        {'.','W','B','B','W','.','W','.'},
        {'B','.','.','B','W','W','W','.'},
        {'W','W','W','B','W','.','B','W'},
        {'.','.','.','W','.','W','.','B'},
        {'B','B','W','B','B','W','W','B'},
        {'W','.','W','W','.','B','.','W'}
// 2
// 5
// "W"
    };
    Solution_lc1958 sol;
    auto ret = sol.checkMove(board, 2, 5, 'W');
    cout << "ret " << ret << endl;
}