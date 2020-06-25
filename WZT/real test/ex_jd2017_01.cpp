// 题目描述
									
// 给你两个集合，要求 {A} + {B}。

// 注：同一个集合中不会有两个相同的元素。

							
// 输入
// 多组（不超过 5 组）数据。

// 每组输入数据分为三行，第一行有两个数字 n,m($0＜n,m\leq10000$)，分别表示集合 A 和集合 B 的元素个数。后两行分别表示集合 A 和集合 B。每个元素为不超出 int 范围的整数，每个元素之间有一个空格隔开。

// 样例输入
// 1 2
// 1
// 2 3
// 1 2
// 1
// 1 2

// 输出
// 针对每组数据输出一行数据，表示合并后的集合，要求从小到大输出，每个元素之间有一个空格隔开。

// 样例输出
// 1 2 3
// 1 2

#include <iostream> 
#include <string>

#include <vector>
#include <algorithm>

using namespace std;

void deal_core(vector<int>& aa, vector<int>& bb, 
                vector<int>& tmpr) {
    sort(aa.begin(), aa.end());
    sort(bb.begin(), bb.end());
    size_t a1 = 0, b1 = 0;
    while (a1 < aa.size() && b1 < bb.size()) {
        if (aa[a1] < bb[b1]) {
            tmpr.push_back(aa[a1]);
            ++a1;
        } else if (aa[a1] == bb[b1])
          	++b1;
        else {
            tmpr.push_back(bb[b1]);
            ++b1;

        }
    }
    for (; a1 != aa.size(); ++a1) {
        tmpr.push_back(aa[a1]);
    }
    for (; b1 != bb.size(); ++b1) {
        tmpr.push_back(bb[b1]);
    }    
}

void print_res(const vector<vector<int> > & res) {
    for (size_t i = 0; i < res.size(); ++i) {
        for (size_t j = 0; ; ++j) {
            cout << res[i][j];
            if (j < res[i].size() - 1)
                cout << " ";
            else {
                cout << endl;
                break;
            }
        }
    }
}

int main() {
	vector<vector<int>> res;
  	int a1 = 0, b1 = 0;
  	while (cin >> a1 >> b1) {
    	vector<int> tmpr;
      	vector<int> aa(a1);
      	vector<int> bb(b1);
      	for (auto aa_it = aa.begin(); aa_it != aa.end(); ++aa_it) {
        	cin >> *aa_it;
        }
      	for (auto bb_it = bb.begin(); bb_it != bb.end(); ++bb_it) {
        	cin >> *bb_it;
        }
      	deal_core(aa, bb, tmpr);
      	res.push_back(tmpr);
    }
  	print_res(res);
  	return 0;
}