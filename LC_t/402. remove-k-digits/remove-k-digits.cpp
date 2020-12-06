

#include "../public_utils/public_utils.h"

class Solution {
public:
    string removeKdigits(string num, int k) {
        int len = num.size();
        int cur = 0, width = k;
        string tmpStr;
        for (int i = 0; i < len - k; i++) {
            char tmpMin = num[cur];
            int mov = 0;
            for (int j = 1; j <= width; j++) {
                if (num[cur + j] < tmpMin) {
                    tmpMin = num[cur + j];
                    mov = j;
                }
            }
            tmpStr.push_back(tmpMin);
            width -= mov;
            cur += mov + 1;
        }
        int firstNotZero = -1;
        for (int i = 0; i < len - k; i++) {
            if (tmpStr[i] != '0') {
                firstNotZero = i;
                break;
            }
        }
        string ret(tmpStr.begin() + firstNotZero, tmpStr.end());
        if (firstNotZero < 0) {
            ret = "0";
        }
        return ret;
    }
};


int main() {
    vector<pair<string, int>> tests = {
        {"100", 1},
        {"1432219", 3}
    };
    Solution sol;
    for (int i = 0; i < tests.size(); i++) {
        string ret = sol.removeKdigits(tests[i].first, tests[i].second);
        cout << "test " << i << " ret: " << ret << endl;
    }
    return 0;
}