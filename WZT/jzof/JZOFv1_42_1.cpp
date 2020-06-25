
#include "stdafx.h"
class Solution {
public:
    string ReverseSentence(string str) {
        stack<string> str_stk;
        string tmp;
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] != ' ') {
                tmp += str[i];
            } else {
                str_stk.push(tmp);
                tmp = "";
            }
        }
        str_stk.push(tmp);
        string ret_str;
        while (false == str_stk.empty()) {
            ret_str += str_stk.top() + " ";
            str_stk.pop();
        }
        return ret_str.substr(0, str.size());
    }
};

int main() {
    Solution totest;
    string test01("I am good.");
    string res = totest.ReverseSentence(test01);
    return 0;
}