// JZOF46:
// 把数字转化为字符串：
// 输入一个数字，返回其可以被映射为多少种字符串，0-a, 1-b, 2-c ... 25-z

#include "stdafx.h"

class Solution {
public:
	int Count_Num_of_Methods(int num) {
		if (num < 0)
			return 0;
		string str_num = to_string((_Longlong) num);
		return Count_Num_of_Methods_Str(str_num);
	}

	int Count_Num_of_Methods_Str(string str) {
		if (str.empty())
			return 0;
		int str_len = str.size();
		vector<int> nums(str_len);
		nums[str_len-1] = 1;
		int res = 1, tmp = 1;
		for (int i = str_len - 2; i >= 0; --i) {
			res = nums[i+1];
			if (str[i] == '1' || 
				(str[i] == '2' && str[i+1] >= '0' && str[i+1] <= '5')) {
					if (i == str_len - 2)
						res += 1;
					else
						res += nums[i+2];
			}
			nums[i] = res;
		}
		res = nums.front();
		return res;
	}
protected:
private:
};

int main() {
	Solution sol1;
	int test1 = 223;
	cout << sol1.Count_Num_of_Methods(test1) << endl;
	return 0;
}