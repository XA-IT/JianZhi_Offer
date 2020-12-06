





#include "../public_utils/public_utils.h"

class Solution {
public:
    int findFirst(vector<int> &arr1, int num, size_t sz1) {
        int le = 0, ri = sz1 - 1;
        int mid;
        while (le < ri) {
            mid = (le + ri) / 2;
            if (arr1[mid] >= num) {
                ri = mid - 1;
            } else {
                le = mid + 1;
            }
        }
        return arr1[le] == num ? le : le + 1;
    }

    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ret;
        sort(arr1.begin(), arr1.end());
        unordered_map<int, int> mp1;
        size_t sz2 = arr2.size();
        size_t sz1 = arr1.size();
        size_t pos = 0;
        int cur;
        if (sz2 <= 0) {
            ret = arr1;
            return ret;
        }
        for (int i = 0; i < sz1; i++) {
            mp1[arr1[i]]++;
        }

        for (int i = 0; i < sz2; i++) {
            cur = arr2[i];
            for (int j = 0; j < mp1[cur]; j++) {
                ret.push_back(cur);
            }
            mp1[cur] = 0;
        }

        for (int i = 0; i < sz1; i++) {
            cur = arr1[i];
            for (int j = 0; j < mp1[cur]; j++) {
                ret.push_back(cur);
            }
        }
        return ret;
    }
};



int main() {
    Solution sol;
    vector<vector<vector<int>>> tests = {
        {{2,3,1,3,2,4,6,7,9,2,19}, {2,1,4,3,9,6}}
    };
    for (int i = 0; i < tests.size(); i++) {
        vector<int> ret = sol.relativeSortArray(tests[i][0], tests[i][1]);
        for (int j = 0; j < ret.size(); j++) {
            cout << ret[j] << ", ";
        }
        cout << endl;
    }
    return 0;
}