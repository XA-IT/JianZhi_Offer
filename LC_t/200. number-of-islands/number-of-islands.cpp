// 200. ��������
// ����һ���� '1'��½�أ��� '0'��ˮ����ɵĵĶ�ά����������������е����������

// �������Ǳ�ˮ��Χ������ÿ������ֻ����ˮƽ�������ֱ���������ڵ�½�������γɡ�

// ���⣬����Լ��������������߾���ˮ��Χ��

// ʾ�� 1:

// ����:
// 11110
// 11010
// 11000
// 00000
// ���: 1
// ʾ�� 2:

// ����:
// 11000
// 11000
// 00100
// 00011
// ���: 3
// ����: ÿ������ֻ����ˮƽ��/����ֱ���������ڵ�½�����Ӷ��ɡ�

#include "../public_utils.h"

class Solution {
private:
    void dfs(vector<vector<char>>& grid, int rowNum,
             int colNum, int x, int y)
    {
        grid[x][y] = '0';
        if (x - 1 >= 0 && grid[x - 1][y] == '1')
            dfs(grid, rowNum, colNum, x - 1, y);
        if (y - 1 >= 0 && grid[x][y - 1] == '1')
            dfs(grid, rowNum, colNum, x, y - 1);
        if (x + 1 < rowNum && grid[x + 1][y] == '1')
            dfs(grid, rowNum, colNum, x + 1, y);
        if (y + 1 < colNum && grid[x][y + 1] == '1')
            dfs(grid, rowNum, colNum, x, y + 1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;
        int rowNum = grid.size(), colNum = grid[0].size();
        int count = 0;
        for (int i = 0; i < rowNum; i++) {
            for (int j = 0; j < colNum; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, rowNum, colNum, i, j);
                }
            }
        }
        return count;
    }
};

int main()
{
    vector<vector<vector<int>>> testsNums = {
        {
            {1, 0, 1, 0, 1},
            {1, 1, 1, 0, 0},
            {1, 0, 0, 0, 0},
            {1, 1, 1, 1, 1},
            {0, 1, 0, 0, 0}
        },
        {
            {1, 0, 1, 0, 1},
            {1, 1, 0, 0, 0},
            {1, 0, 0, 0, 0},
            {1, 1, 1, 1, 1},
            {0, 1, 0, 0, 0}
        }
    };
    vector<vector<char>> test2 = {
        {'1','1','1','1','1','1','1'},
        {'0','0','0','0','0','0','1'},
        {'1','1','1','1','1','0','1'},
        {'1','0','0','0','1','0','1'},
        {'1','0','1','0','1','0','1'},
        {'1','0','1','1','1','0','1'},
        {'1','1','1','1','1','1','1'}
    };
    Solution sol;
    for (vector<vector<int>> testNums : testsNums) {
        vector<vector<char>> testChars = transIntMatrix2Chars(testNums);
        printMatrix(testChars);
        int res = sol.numIslands(testChars);
        cout << "result is: " << res << endl; 
    }
    printMatrix(test2);
    int res = sol.numIslands(test2);
    printMatrix(test2);
    cout << "result is: " << res << endl; 
    return 0;
}