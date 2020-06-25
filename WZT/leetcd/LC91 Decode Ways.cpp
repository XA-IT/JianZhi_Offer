// A message containing letters from A-Z is being encoded to 
// numbers using the following mapping:

// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given a non-empty string containing only digits, determine the total number of ways to decode it.

// Example 1:

// Input: "12"
// Output: 2
// Explanation: It could be decoded as "AB" (1 2) or "L" (12).
// Example 2:

// Input: "226"
// Output: 3
// Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

#include "stdafx.h"
class Solution {
public:
    // f(n) = f(n - 1) * isvalid(s(n - 1)) + 
    //        f(n - 2) * isvalid(s(n - 2, n - 1))
    // zheng xiang
    int isvalid(string subs) {
        if (!subs.size()) return 0;
        if (subs.size() > 2) return 0;
        if (subs.size() == 2 && subs[0] == '0') return 0;
        int tmp = stoi(subs);
        if (tmp >= 1 && tmp <= 26) {
            return 1;
        } else {
            return 0;
        }
    }
    
    int numDecodings(string s) {
        if (!s.size()) return 0;
        int res = 0, len = s.size(), tmp = 0;
        int f1 = isvalid(s.substr(0, 1));
        if (len <= 1)
            return f1;
        int f2 = f1 * isvalid(s.substr(1, 1)) + isvalid(s.substr(0, 2));
        if (len == 2) return f2;
        for (size_t i = 2; i < s.size(); ++i) {
            tmp = f2;
            f2 = f2 * isvalid(s.substr(i, 1)) + f1 * isvalid(s.substr(i - 1, 2));
            f1 = tmp;
        }
        //res = f1 + f2;
        return f2;
    }
};

string test01() {
    return "101";
}

int main() {
    Solution test1;
    string totest1 = test01();
    cout << test1.numDecodings(totest1);
    return 0;
}