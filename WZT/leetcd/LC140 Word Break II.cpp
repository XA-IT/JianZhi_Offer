// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

// Note:

// The same word in the dictionary may be reused multiple times in the segmentation.
// You may assume the dictionary does not contain duplicate words.
// Example 1:

// Input:
// s = "catsanddog"
// wordDict = ["cat", "cats", "and", "sand", "dog"]
// Output:
// [
//   "cats and dog",
//   "cat sand dog"
// ]
// Example 3:

// Input:
// s = "catsandog"
// wordDict = ["cats", "dog", "sand", "and", "cat"]
// Output:
// []

#include "stdafx.h"

class Solution {
public:
    unordered_map<string, vector<string>> m;    //存储从前向后每个子串可能的组合
    //dp算法, 需要保存之前的结果
    vector<string> combine(string s, vector<string> tocomb) {
        for (size_t i = 0; i < tocomb.size(); ++i) {
            tocomb[i] += " " + s;
        }
        return tocomb;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (m.count(s)) return m[s];
        //自后向前dp
        //if (!s.size() || !wordDict.size()) return { };
        size_t dictlen = wordDict.size();
        vector<string> res;
        if (find(wordDict.begin(), wordDict.end(), s) != wordDict.end()) 
            res.push_back(s);
        for (size_t i = 1; i < s.size(); i++) {
            string cur_word = s.substr(i);
            if (find(wordDict.begin(), wordDict.end(), cur_word) 
                != wordDict.end()) {
                string rem_str = s.substr(0, i);
                vector<string> tmpres = combine(cur_word, wordBreak(rem_str, wordDict));
                res.insert(res.end(), tmpres.begin(), tmpres.end());
            }
        }
        m[s] = res;
        return res;
    }
};