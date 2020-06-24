// test0423.cpp : 定义控制台应用程序的入口点。
// 某团的笔试 黑白jz, 即矩阵中任意元素上下左右均相等且不等于该元素
// 输入一个, 输出至少要修改多少元素才能变为黑白jz

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int min_modify(vector<vector<int>> &mtrx) {
	map<int, int> res_odd, res_even;
	const size_t rown = mtrx.size();
	if (!rown)
		return 0;
	const size_t coln = mtrx[0].size();
	for (size_t cur_row = 0; cur_row < rown; ++cur_row) {
		for (size_t cur_col = 0; cur_col < coln; ++cur_col) {
			int cur_num = mtrx[cur_row][cur_col];
			if ((cur_col + cur_row) % 2) {
				if (res_even.count(cur_num) == 0) {
					res_even[cur_num] = 1;
				} else {
					res_even[cur_num]++;
				}
			} else {
				if (res_odd.count(cur_num) == 0) {
					res_odd[cur_num] = 1;
				} else {
					res_odd[cur_num]++;
				}
			}
		}
	}

	// find most and 2nd num
	int e_1st = 0, e_1st_count = 0, e_2nd = 0, e_2nd_count = 0;
	for (auto even_it = res_even.begin(); even_it != res_even.end(); ++even_it) {
		if (even_it->second >= e_2nd_count) {
			if (even_it->second >= e_1st_count) {
				e_2nd_count = e_1st_count;
				e_2nd = e_1st;
				e_1st_count = even_it->second;
				e_1st = even_it->first;
			} else {
				e_2nd_count = even_it->second;
				e_2nd = even_it->first;
			}
		}
	}
	int o_1st = 0, o_1st_c = 0, o_2nd = 0, o_2nd_c = 0;
	for (auto odd_it = res_odd.begin(); odd_it != res_odd.end(); ++odd_it) {
		if (odd_it->second >= o_2nd_c) {
			if (odd_it->second >= o_1st_c) {
				o_2nd_c = o_1st_c;
				o_2nd = o_1st;
				o_1st = odd_it->first;
				o_1st_c = odd_it->second;
			} else {
				o_2nd_c = odd_it->second;
				o_2nd = odd_it->first;
			}
		}
	}
	int res = 0, maxnum = (int)coln * rown;
	if (o_1st != e_1st) {
		res = maxnum - o_1st_c - e_1st_count;
	} else {
		res = maxnum - max(o_1st_c + e_2nd_count, o_2nd_c + e_1st_count);
	}
	return res;
}

int main()
{
	int m1, n1, tmp;
	cin >> m1 >> n1;
	vector<vector<int>> mtrx;
	for (size_t cur_row = 0; cur_row < m1; ++cur_row) {
		vector<int> tmp_row;
		for (size_t cur_col = 0; cur_col < n1; ++cur_col) {
			cin >> tmp;
			tmp_row.push_back(tmp);
		}
		mtrx.push_back(tmp_row);
	}
	int res = min_modify(mtrx);
	cout << res << endl;
	return 0;
}

