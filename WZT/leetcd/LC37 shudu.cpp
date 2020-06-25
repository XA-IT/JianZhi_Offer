//数独游戏
#include "pch.h"
#include "stdafx.h"

class Solution {
private:
    struct cell {
        int val;
        int numPossible;
        bitset<10> used;
        cell() : val(0), numPossible(9) {}
    };
    cell sell;
    array<array<cell, 9>, 9> cells;
    //----------------------------------
    // 按照已有约束尝试更新cell的值
    //----------------------------------

    // 将(i,j)的值设为v
    bool setVal(int i, int j, int v) {
        cell &cur = cells[i][j];
        if (cur.val == v) return true;
        if (cur.used[v]) return false;
        //set cell
        cur.used.set();
        cur.used.reset(v);
        cur.numPossible = 1;
        cur.val = v;

        //set other cells cons
        for (int k = 0; k < 9; ++k) {
            if (i != k && !updateConstraints(k, j, v)) return false;
            if (j != k && !updateConstraints(i, k, v)) return false;
            //3*3:
            int ix = (i / 3) * 3 + k / 3;
            int jx = (j / 3) * 3 + k % 3;
            if (ix != i && jx != j && !updateConstraints(ix, jx, v)) return false;
        }
        return true;
    }

    //upd
    bool updateConstraints(int i, int j, int v) {
        cell &cur = cells[i][j];
        if (cur.used[v]) return true;
        if (cur.val == v) return false;

        //upd cons
        cur.used.set(v);
        if (--cur.numPossible > 1) return true;
        for (int val = 1; val <= 9; ++val) {
            if (false == cur.used[val]) return setVal(i, j, val);
        }
        assert(false);      //sth goes wrong
    }

    //try to set it
    //------------------------------
    //backtracking
    //------------------------------
    vector<pair<int, int>> bt;  //record the posi of cell

    bool findValForEmptyCells() {
        bt.clear();
        //find all empty cells
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (0 == cells[i][j].val)
                    bt.push_back(make_pair(i, j));
            }
        }
        sort(bt.begin(), bt.end(),
            [this](const pair<int, int> &lhs, const pair<int, int> &rhs)
        { return cells[lhs.first][lhs.second].numPossible < cells[rhs.first][rhs.second].numPossible; });
        return backTrack(0);
    }

    //对于>=k的index查找其val
    bool backTrack(int k) {
        if (k >= bt.size()) return true;
        int i = bt[k].first, j = bt[k].second;
        //有可能更新限制时确定了cell的val
        if (cells[i][j].val != 0) return backTrack(k + 1);

        auto cons = cells[i][j].used;
        array<array<cell, 9>, 9> snapshot(cells);
        for (int val = 1; val <= 9; ++val) {
            if (0 == cons[val]) {
                if (setVal(i, j, val)) {
                    if (backTrack(k + 1))
                        return true;
                }
                cells = snapshot;
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        cells = array<array<cell, 9>, 9>();
        if (board.empty()) return;
        int m = board.size(), n = board[0].size();
        if (m != 9 || n != 9) return;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.')
                    continue;
                else {
                    if (false == setVal(i, j, board[i][j] - '0'))
                        return;
                }
            }
        }

        if (false == findValForEmptyCells()) return;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                board[i][j] = cells[i][j].val + '0';
            }
        }
    }
};

int main() {
    vector<vector<char>> test1 = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    Solution s1;
    Solution().solveSudoku(test1);
    return 0;
}