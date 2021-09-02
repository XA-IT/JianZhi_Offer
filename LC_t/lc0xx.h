#pragma once

#include "public_utils/public_utils.h"

class Solution_lc30 {
    bool isContained(unordered_map<string, int> wordMap, const string &s, int beg, int slen, int wordlen, int wordnum) {
        int metword = 1;
        while (metword < wordnum && beg <= (slen - wordlen)) {
            const string tmpStr = s.substr(beg, wordlen);
            if (wordMap.count(tmpStr) && wordMap[tmpStr]) {
                wordMap[tmpStr]--;
                beg += wordlen;
                metword++;
            } else {
                return false;
            }
        }
        return (metword == wordnum);
    }
public:
    vector<int> findSubstring(const string s, vector<string>& words) {
        vector<int> ret;
        if (words.size() <= 0) {
            return ret;
        }
        int wordnum = words.size();
        int wordlen = words[0].size();
        const int slen = s.size();
        const int totalword = wordlen * wordnum;
        int beg = 0;
        unordered_map<string, int> wordMap;
        // 构建单词数量统计
        for (auto word : words) {
            wordMap[word]++;
        }
        // 滑动窗口，遇到合法的起始单词，判断接下来的单词是否满足条件
        while (beg <= (slen - totalword)) {
            const string begStr = s.substr(beg, wordlen);
            if (wordMap.count(begStr)) {
                wordMap[begStr]--;
                // 直接对map进行操作并传递太浪费了，应该用数组来表示
                if (isContained(wordMap, s, beg + wordlen, slen, wordlen, wordnum)) {
                    ret.push_back(beg);
                }
                wordMap[begStr]++;
            }
            beg++;
        }
        return ret;
    }
};