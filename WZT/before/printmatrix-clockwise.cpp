//// test1.cpp : 定义控制台应用程序的入口点。
////
//
//顺时针打印矩阵
//题目描述
//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
//#include "stdafx.h"
#include <iostream>
//#include <queue>
#include <stdlib.h>
#include <vector>

using namespace std;
//
#include <windows.h>
#include <stdio.h>
#include <process.h>


unsigned Counter = 0;
void printmatrix(vector < vector<int> >matrix) {
	if (matrix.size() == 0)
		return;
	int m = matrix.size();
	int n = matrix[0].size();
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << matrix[i][j] << "  ";
		}
		cout << endl;
	}
}

vector<int> printMatrix(vector<vector<int> > matrix) {
	vector<int> output;
	if (matrix.size() == 0)
		return output;

	int col_num = matrix[0].size();
	int row_num = matrix.size();
	int i = 1, j = 1;
	int done_c = 0, done_r = 0;
	int nextstate = 0;
	bool ismbigger = false;
	if (col_num < row_num)
		ismbigger = true;
	while (!(ismbigger && done_r == col_num && done_c == col_num)
		&& !(!ismbigger && done_r == row_num && done_c == row_num - 1)) {
		switch (nextstate) {
		case 0:
		{
			while (j < col_num - done_c * 0.5) {
				output.push_back(matrix[i-1][j-1]);
				++j;
			}
			output.push_back(matrix[i-1][j-1]);
			++done_r;
			++i;
			nextstate = 1;
			break;
		}
		case 1:
		{
			while (i < row_num - (done_r-1)*0.5 ) {
				output.push_back(matrix[i-1][j-1]);
				++i;
			}
			output.push_back(matrix[i-1][j-1]);
			++done_c;
			--j;
			nextstate = 2;
			break;
		}
		case 2:
		{
			while (j > (done_c - 1)*0.5 + 1 ) {
				output.push_back(matrix[i-1][j-1]);
				--j;
			}
			output.push_back(matrix[i-1][j-1]);
			++done_r;
			--i;
			nextstate = 3;
			break;
		}
		case 3:
		{
			while (i > (done_r)*0.5 + 1) {
				output.push_back(matrix[i-1][j-1]);
				--i;
			}
			output.push_back(matrix[i-1][j-1]);
			++done_c;
			++j;
			nextstate = 0;
			break;
		}
		}
	}
	//output.pop_back();
		return output;
}
int main()
{ 

	vector<int> ttt;
	ttt.push_back(3);
	
	vector<vector<int>> matrix_t;
	//*****************test for matrix**********************///
	int testin = 1;
	for (int i = 0; i < 4; ++i) {
		ttt.clear();
		for (int j = 0; j < 5; ++j) {
			cout << testin << "  ";
			ttt.push_back(testin++);
		}
		matrix_t.push_back(ttt);
		cout << endl;
	}
	printmatrix(matrix_t);
	ttt.clear();
	ttt = printMatrix(matrix_t);
	testin = 0;
	for (auto ttIt = ttt.begin(); ttIt != ttt.end(); ++ttIt) {
		cout << *ttIt << "  ";
	}
	//************************end of test
	system("pause");
	return 0;
	//HANDLE hThread;
	//unsigned threadID;
	//printf( "Creating second thread...\n" );
	//// Create the second thread.
	//hThread = (HANDLE)_beginthreadex( NULL, 0, &SecondThreadFunc, NULL, 0, &threadID );
	////只是为了防止主线程退出!
	//WaitForSingleObject( hThread, INFINITE);
	//CloseHandle( hThread );
}









