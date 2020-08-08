// 763. 划分字母区间
// 字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。
// 返回一个表示每个字符串片段的长度的列表。

// 示例 1：

// 输入：S = "ababcbacadefegdehijhklij"
// 输出：[9,7,8]
// 解释：
// 划分结果为 "ababcbaca", "defegde", "hijhklij"。
// 每个字母最多出现在一个片段中。
// 像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。

// 提示：

// S的长度在[1, 500]之间。
// S只包含小写字母 'a' 到 'z' 。
#include "../public_utils/public_utils.h"

class Solution {
public:
    vector<int> partitionLabels(string S) {
        if (S.empty())
            return { };
        int sz = S.size();
        vector<int> count(26, 0);
        for (int i = 0; i < sz; i++) {
            count[S[i] - 'a'] = i;
        }
        vector<int> ret;
        int riMax = count[S[0] - 'a'], le = 0;
        for (int i = 0; i < sz; i++) {
            if (count[S[i] - 'a'] > riMax) {
                riMax = count[S[i] - 'a'];
            }
            else if (i == riMax) {
                ret.push_back(riMax - le + 1);
                le = i + 1;
                if (le < sz)
                    riMax = count[S[le] - 'a'];
            }
        }
        return ret;
    }
};

int main()
{
    vector<string> tests = {
        "ababcbacadefegdehijhklij",
        "aab",
        "caedbdedda"
    };
    Solution sol;
    for (string test : tests) {
        vector<int> ret = sol.partitionLabels(test);
        cout << "input str: " << test << endl
             << "result: ";
        for (auto vecIt = ret.begin(); vecIt != ret.end(); vecIt++) {
            cout << *vecIt << " ";
        }
        cout << endl;
    }
}