// Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.
// The matching should cover the entire input string (not partial).

// Note:

// s could be empty and contains only lowercase letters a-z.
// p could be empty and contains only lowercase letters a-z, and characters like . or *.
// Example 1:

// Input:
//     s = "aa"
//     p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
// Example 2:

// Input:
//     s = "aa"
//     p = "a*"
// Output: true
// Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
// Example 3:

// Input:
//     s = "ab"
//     p = ".*"
// Output: true
// Explanation: ".*" means "zero or more (*) of any character (.)".
#include "stdafx.h"

class Solution {
public:
    // solution 1, recursion
    // 首先考虑第一位是否一致, 将第二位单独考虑
    bool isMatch1(string s, string p) {
        if (!p.size()) return !s.size();
        bool first_match = (s.size() && 
                            (p[0] == '.' || p[0] == s[0]));
        if (p.size() > 1 && p[1] == '*') {
            return (isMatch1(s, p.substr(2)) 
                    || (first_match && isMatch1(s.substr(1), p)));
        } else {
            return first_match && isMatch1(s.substr(1), p.substr(1));
        }
    }
    // solution 2, dp
    // 记录每次对比的结果, 避免重复对比
    enum res {
        NOTH, 
        FALSE, 
        TRUE
    };
    
    bool isMatch2(string s, string p) {
        size_t sl = s.size(), pl = p.size();
        vector<vector<res>> memo(sl + 1, vector<res>(pl + 1, res::NOTH));
        return dp(0, 0, s, p, memo);
    }
    
    bool dp(size_t i, size_t j, string s, string p, 
            vector<vector<res>> &memo) {
        // check the res
        if (memo[i][j] != res::NOTH) {
            return memo[i][j] == res::TRUE;
        }
        bool tmp_ans;
        if (j == p.size()) {
            tmp_ans = (i == s.size());
        } else {
            bool first_match = (i < s.size() && 
                                (p[j] == '.' || p[j] == s[i]));
            if (j < p.size() - 1 && p[j + 1] == '*') {
                tmp_ans = (first_match && dp(i + 1, j, s, p, memo)) 
                            || dp(i, j + 2, s, p, memo);
            } else {
                tmp_ans = first_match && dp(i+1, j+1, s, p, memo);
            }
        }
        memo[i][j] = tmp_ans? res::TRUE : res::FALSE;
        return tmp_ans;
    }

    // solution 3, backtracking
    bool isMatch3(string s, string p) {
        int m = s.length(), n = p.length();
        return backtracking(s, m, p, n);
    }
    
    bool backtracking(string& s, int i, string& p, int j) {
        if (i == 0 && j == 0) return true;
        if (i != 0 && j == 0) return false;
        if (i == 0 && j != 0) {
            //in this case only p == "c*c*c*" this pattern can match null string
            if (p[j-1] == '*') {
                return backtracking(s, i, p, j-2);
            }
            return false;
        }
        //now both i and j are not null
        if (s[i-1] == p[j-1] || p[j-1] == '.') {
            return backtracking(s, i - 1, p, j - 1);
        } else if (p[j-1] == '*') {
            //two cases: determines on whether p[j-2] == s[i-1]
            //first p[j-2]* matches zero characters of p
            if (backtracking(s, i, p, j - 2)) return true;
            //second consider whether p[j-2] == s[i-1], if true, then s[i-1] is matched, move to backtracking(i - 1, j)
            if (p[j-2] == s[i-1] || p[j-2] == '.') {
                return backtracking(s, i - 1, p, j);
            }
            return false;
        }
        return false;
    }
};