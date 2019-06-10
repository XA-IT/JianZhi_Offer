// 丑数
// 题目描述
// 把只包含质因子2、3和5的数称作丑数（Ugly Number）。
// 例如6、8都是丑数，但14不是，因为它包含质因子7。
// 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
#include "stdafx.h"

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index < 0) 
            return 0;
        if (index < 7) 
            return index;
        vector<int> nums(index);
        // note: 必须为nums中的值
        int p2 = 0, p3 = 0, p5 = 0;
        nums[0] = 1;
        for (int i = 1; i < index; ++i) {
            nums[i] = min(nums[p2] * 2, min(nums[p3] * 3, nums[p5] * 5));
            if (nums[p2] * 2 == nums[i]) ++p2;
            if (nums[p3] * 3 == nums[i]) ++p3;
            if (nums[p5] * 5 == nums[i]) ++p5;
        }
        return nums.back();
    }
};
