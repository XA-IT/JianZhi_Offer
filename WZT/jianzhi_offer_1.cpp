//题目描述:
//	定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。


class Solution {
public:
	stack<int> stk_min;
	stack<int> stk_data;
	void push(int value) {
		if(stk_min.size() == 0 || value < stk_min.top())
			stk_min.push(value);
		else 
			stk_min.push(stk_min.top());
	}
	void pop() {
		stk_data.pop();
		stk_min.pop();

	}
	int top() {
		return stk_data.top();

	}
	int min() {
		return stk_min.top();
	}
};