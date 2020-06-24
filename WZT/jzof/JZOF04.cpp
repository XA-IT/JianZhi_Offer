// 二维数组中的查找

// 在一个二维数组中（每个一维数组的长度相同），
// 每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
// 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
#include "stdafx.h"

bool findNum(vector<vector<int>>& array, int target) {
    int row = array.size();
    int column = array[0].size();
    if(!row || !column)
        return false;
    //bool existed = false;
    int row_index = 0, col_index = column - 1;
    while(col_index >= 0 && row_index < row)
    {
        if(array[row_index][col_index]>target)
            col_index--;
        else if(array[row_index][col_index]<target)
            row_index++;
        else {
            return true;
        }                
    }
    return false;
}