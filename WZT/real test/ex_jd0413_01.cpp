// 给出m个字符串s1,..., sm, 和一个字符串t, 输出字符串个数使得 子串互bu相交, 都是sm中的某个串

#include <string>
#include <vector>
#include <iostream>

using namespace std;


int CountSubstr(vector<string> s) {
    if (s.size() < 2) return 0;
    string str = s.back();
    int counter = 0, maxcount = 0;
    for (size_t i = 0; i < s.size() - 1; ++i) {
        auto posi = str.find(s[i]);
        if (posi == string::npos)
            continue;
        else {
            counter = 1;
            for (size_t j = i + 1; j < s.size() - 1; ++j) {
                size_t nexposi = str.find(s[j], posi);
                if (nexposi != string::npos) {
                    ++counter;
                    posi = nexposi;
                }
            }
            if (maxcount < counter) 
                maxcount = counter;
        }
    }
    return maxcount;
}

int main() {
    string s;
    // vector<string> svec;
    // while (cin >> s) {
    //     svec.push_back(s);
    // }
    vector<string> svec = {
        "aabbd",
        "aabbc"
    };
    int res = CountSubstr(svec);
    cout << res << endl;
    return 0;
}