// 给定两个单词 word1 和 word2，找到使得 word1 和 word2 相同所需的最小步数，每步可以删除任意一个字符串中的一个字符。

//  

// 示例：

// 输入: "sea", "eat"
// 输出: 2
// 解释: 第一步将"sea"变为"ea"，第二步将"eat"变为"ea"
//  

// 提示：

// 给定单词的长度不超过500。
// 给定单词中的字符只含有小写字母。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/delete-operation-for-two-strings
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include "../public_utils.h"

class Solution {
public:
    // 方法一采用递归运行速度较慢
    // int calSameLen(string word1, int idx1, string word2, int idx2, vector<vector<int>> &tmp) {
    //     if (idx1 == 0 || idx2 == 0)
    //         return 0;
    //     if (tmp[idx1][idx2] >= 0)
    //         return tmp[idx1][idx2];
    //     if (word1[idx1 - 1] == word2[idx2 - 1]) {
    //         tmp[idx1][idx2] = calSameLen(word1, idx1 -1, word2, idx2 - 1, tmp) + 1;
    //         return tmp[idx1][idx2];
    //     }
    //     tmp[idx1][idx2] = max(calSameLen(word1, idx1 - 1, word2, idx2, tmp), 
    //                           calSameLen(word1, idx1, word2, idx2 - 1, tmp));
    //     return tmp[idx1][idx2];
    // }

    // int minDistance(string word1, string word2) {
    //     int sz1 = word1.size(), sz2 = word2.size();
    //     int idx1 = 0, idx2 = 0;
    //     vector<vector<int>> tmpret(sz1 + 1, vector<int> (sz2 + 1, -1));
    //     return sz1 + sz2 - 2 * calSameLen(word1, sz1, word2, sz2, tmpret);
    // }
    int minDistance(string word1, string word2) {
        int sz1 = word1.size(), sz2 = word2.size();
        int ret = 0;
        int tmpret[sz1 + 1][sz2 + 1];
        memset(tmpret, 0, sizeof(tmpret));
        for (int i = 0; i < sz1; i++) {
            for (int j = 0; j < sz2; j++) {
                if (word1[i] == word2[j]) {
                    tmpret[i + 1][j + 1] = tmpret[i][j] + 1;
                }
                else {
                    tmpret[i + 1][j + 1] = max(tmpret[i + 1][j], tmpret[i][j + 1]);
                }
                ret = max(ret, tmpret[i + 1][j + 1]);
            }
        }
        return sz1 + sz2 - 2 * ret;
    }
};

int main() {
    vector<pair<string, string>> tests = {
        {"abc", "bcd"},
        {"abcde", "fghij"},
        {"sea", "eat"}
    };
    Solution sol;
    vector<int> results;
    for (pair<string, string> test : tests) {
        int ret = sol.minDistance(test.first, test.second);
        cout << ret << endl;
        results.push_back(ret);
    }
    return 0;
}