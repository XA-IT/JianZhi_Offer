// 字符串的排列
// 题目描述
// 输入一个字符串,按字典序打印出该字符串中字符的所有排列。
// 例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。

// 输入描述:
// 输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。

#include "stdafx.h"

class Solution {
public:
    vector<string> Permutation(string str) {        
        //sort(str.begin(), str.end());
        vector<string> res;
        if (str.size() == 0)
            return { };
        if (str.size() == 1) {
            res.push_back(str);
            return res;
        }
        Permutation(str, res, 0);
        sort(res.begin(), res.end());
        return res;
    }
    
    void Permutation(string str, vector<string> &res,
                     size_t beg) {
        string tmpstr = str;
        if (beg == str.size()) {
            res.push_back(str);
            return;
        }
        for (size_t cur = beg; cur != str.size(); ++cur) {
            if (cur != beg && str[cur] == str[beg])
                continue;
            swap(str[cur], str[beg]);
            Permutation(str, res, beg + 1);
            swap(str[cur], str[beg]);
        }
    }
};