#pragma once
#include "public_utils/public_utils.h"

class Solution_lc1624 {
    struct NodeTmp {
        int pos;
        int lengthMin;
        NodeTmp() : pos(-1), lengthMin(-1) {};
    };
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<NodeTmp> mp;
        mp.resize(26);

        int sz = s.size();
        for (int i = 0; i < sz; i++) {
            int ch = s[i] - 'a';
            if (mp[ch].pos != -1) {
                mp[ch].lengthMin = max(mp[ch].lengthMin, i - mp[ch].pos - 1);
            } else {
                mp[ch].pos = i;
            }
        }
        int ret = -1;  
        for (int i = 0; i < 26; i++) {
            if (mp[i].lengthMin != -1) {
                ret = max(ret, mp[i].lengthMin);
            }
        }
        return ret;
    }
};

inline void TestLc1624() {
    vector<string> tests = {/* "aa", "babcc", "abc",  */"mgntdygtxrvxjnwksqhxuxtrv"};
    vector<int> ans = {/* 0, 0, -1,  */18};
    Solution_lc1624 sol;
    for (int i = 0; i < tests.size(); i++) {
        auto ret = sol.maxLengthBetweenEqualCharacters(tests[i]);
        cout << (ret == ans[i]) << ", exp: " << ans[i] << ", act: " << ret << endl;
    }
    return;
}