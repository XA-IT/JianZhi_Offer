// JZOF47: 礼物的最大价值
// 一个m*n的棋盘上每一格都表示一个礼物的价值，从左上角开始，
//每次向左或向下移动一格，直到右下角，求最多能有多少价值的礼物

#include "stdafx.h"

class Solution {
public:
	int Max_Gift(vector<vector<int>> table) {
		if (table.empty())
			return 0;
		int row_n = table.size(), col_n = table.front().size();
		vector<vector<int>> res = table;
		for (int i = 1; i < col_n; ++i) {
			res[0][i] += res[0][i-1];
		}
		for (int i = 1; i < row_n; ++i) {
			res[i][0] += res[i-1][0];
		}
		for (int i = 1; i < row_n; ++i) {
			for (int j = 1; j < col_n; ++j)
				res[i][j] += max(res[i-1][j], res[i][j-1]);
		}
		return res.back().back();
	}
};

int main() {
	Solution sol1;
	vector<int> tmp;
	vector<vector<int>> test1;
	tmp.push_back(1);
	tmp.push_back(10);
	tmp.push_back(3);
	tmp.push_back(8);
	test1.push_back(tmp);
	tmp.clear();
	tmp.push_back(12);
	tmp.push_back(2);
	tmp.push_back(9);
	tmp.push_back(6);
	test1.push_back(tmp);
	tmp.clear();
	tmp.push_back(5);
	tmp.push_back(7);
	tmp.push_back(4);
	tmp.push_back(11);
	test1.push_back(tmp);
	tmp.clear();
	tmp.push_back(3);
	tmp.push_back(7);
	tmp.push_back(16);
	tmp.push_back(5);
	test1.push_back(tmp);
	tmp.clear();
	cout << sol1.Max_Gift(test1) << endl;
	return 0;
}