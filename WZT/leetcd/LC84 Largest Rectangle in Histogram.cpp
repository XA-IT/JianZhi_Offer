//Given n non-negative integers representing the histogram's bar height 
//where the width of each bar is 1, find the area of largest rectangle in the histogram.
//Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
//The largest rectangle is shown in the shaded area, which has area = 10 unit.

class Solution {
public:
    // 使用stack按单调增长顺序存储序列的值, 
    // 当出现减小的元素时开始回头检查当前元素的前一元素 到最前的大于等于当前元素之间的矩形
    // 由于是前一元素, 故在最初向末尾放0
    // 当stack为空时证明从0开始的所有元素均小于等于当前元素, 故计算的矩形长度+1
    int largestRectangleArea(vector<int>& heights) {
        int length = heights.size();
        
        if (!length)
            return 0;
        if (length < 2) 
            return heights[0];
        stack<int> st;
        int res = 0;
        int i = 0, j = 0, h = 0;
        heights.push_back(0);
        ++ length;
        while (i < length) {
            if (st.empty() || heights[i] > heights[st.top()])
                st.push(i++);
            else {
                h = heights[st.top()];
                st.pop();
                j = st.empty()? -1 : st.top();
                res = max(res, h * (i - j - 1));
            }
        }
        return res;
    }
};