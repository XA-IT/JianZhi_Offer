// 题目描述
// n个人（编号0~(n-1))，从0开始报数，报到(m-1)的退出，剩下的人 继续从0开始报数。求胜利者的编号。
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if (n <= 0)
            return -1;
        int s = 0;
        for (int i = 2; i <= n; ++i)
            s = (s + m) % i;
        return s;
    }
};

// f(n, m) = (f(n-1, m) + m) % n