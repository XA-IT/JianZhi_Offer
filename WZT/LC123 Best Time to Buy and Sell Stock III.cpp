// Say you have an array for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete at most two transactions.

// Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

// Example 1:

// Input: [3,3,5,0,0,3,1,4]
// Output: 6
// Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
//              Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
// Example 2:

// Input: [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
//              Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
//              engaging multiple transactions at the same time. You must sell before buying again.
// Example 3:

// Input: [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.
#include "stdafx.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        if (length < 2) return 0;
        //需要考虑交易次数
        //必须要遍历所有的可能, 不能只看递增或递减性
        int tradetime = 2;
        vector<vector<int>> pf(tradetime + 1, vector<int>(length, 0));
        int idx = 1, res = 0;
        for (int i = 1; i <= tradetime; ++i) {
            int tmpmax = pf[i - 1][0] - prices[0];
            for (int j = 1; j < length; ++j) {
                pf[i][j] = max(pf[i][j - 1], tmpmax + prices[j]);
                tmpmax = max(tmpmax, pf[i - 1][j] - prices[j]);
                res = max(res, pf[i][j]);
            }
        }
        return res;
    }
};

int main() {
    Solution totest;
    vector<int> prices = {3, 3, 5, 0, 3, 1, 4};
    cout << totest.maxProfit(prices) << endl;
    system("pause");
    return 0;
}