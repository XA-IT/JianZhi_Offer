/*
包含min函数的栈
题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
*/

class Solution {
public:
	void push(int value) {
		datastack.push(value);
		if(minstack.empty() || value < minstack.top()){
			minstack.push(value);
		}
	}
	void pop() {
		if(minstack.top() == datastack.top() && !minstack.empty()){
			minstack.pop();    
		}
		if(!datastack.empty()){
			datastack.pop();    
		}
	}
	int top() {
		return datastack.top();
	}
	int min() {
		return minstack.top();
	}
private:
	stack<int> datastack;
	stack<int> minstack;
};
