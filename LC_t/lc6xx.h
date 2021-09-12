#pragma once 

#include "public_utils/public_utils.h"

class Solution_lc678 {
public:
    bool checkValidString(string s) {
        int sz = s.size();
        vector<int> left(sz, -1), star(sz, -1), right(sz, -1);
        int nle = 0, nst = 0, nri = 0;
        for (int i = 0; i < sz; i++) {
            if (s[i] == '(') {
                left[nle] = i;
                nle++;
            } else if (s[i] == '*') {
                star[nst] = i;
                nst++;
            } else {
                if (nle > 0) {
                    nle--;
                    left[nle] = -1;
                } else if (nst > 0) {
                    nst--;
                    star[nst] = -1;
                } else {
                    return false;
                }
            }
        }
        if (nle > 0) {
            while (nle > 0) {
                nst--;
                nle--;
                if (nst < 0 || star[nst] < left[nle]) {
                    return false;
                }
            }
        }
        return true;
    }
};