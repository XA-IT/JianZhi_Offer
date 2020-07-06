// �����������ʁ0�2word1�0�2�́0�2word2���ҵ�ʹ�Á0�2word1�0�2�́0�2word2�0�2��ͬ�������С������ÿ������ɾ������һ���ַ����е�һ���ַ���

// �0�2

// ʾ����

// ����: "sea", "eat"
// ���: 2
// ����: ��һ����"sea"��Ϊ"ea"���ڶ�����"eat"��Ϊ"ea"
// �0�2

// ��ʾ��

// �������ʵĳ��Ȳ�����500��
// ���������е��ַ�ֻ����Сд��ĸ��

// ��Դ�����ۣ�LeetCode��
// ���ӣ�https://leetcode-cn.com/problems/delete-operation-for-two-strings
// ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

#include "../public_utils.h"

class Solution {
public:
    // ����һ���õݹ������ٶȽ���
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