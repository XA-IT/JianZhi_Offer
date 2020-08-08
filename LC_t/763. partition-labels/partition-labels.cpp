// 763. ������ĸ����
// �ַ��� S ��Сд��ĸ��ɡ�����Ҫ������ַ�������Ϊ�����ܶ��Ƭ�Σ�ͬһ����ĸֻ����������е�һ��Ƭ�Ρ�
// ����һ����ʾÿ���ַ���Ƭ�εĳ��ȵ��б�

// ʾ�� 1��

// ���룺S = "ababcbacadefegdehijhklij"
// �����[9,7,8]
// ���ͣ�
// ���ֽ��Ϊ "ababcbaca", "defegde", "hijhklij"��
// ÿ����ĸ��������һ��Ƭ���С�
// �� "ababcbacadefegde", "hijhklij" �Ļ����Ǵ���ģ���Ϊ���ֵ�Ƭ�������١�

// ��ʾ��

// S�ĳ�����[1, 500]֮�䡣
// Sֻ����Сд��ĸ 'a' �� 'z' ��
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