#include "../public_utils/public_utils.h"

/*
    for 状态1 in 状态1的所有取值：
        for 状态2 in 状态2的所有取值：
            for ...
                dp[状态1][状态2][...] = 择优(选择1，选择2...)
*/

class solution_knapsack {
public:
    int knapsack(vector<int> &weights, vector<int> &val, int n, int w) {
        vector<vector<int>> dp(n, vector<int> (w + 1, -1));
        if (weights[0] < w) {
            dp[0][weights[0]] = val[0];    
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= w; j++) {
                if (dp[i - 1][j] >= 0) {
                    dp[i][j] = dp[i - 1][j];
                }
            }
            for (int j = 0; j <= w - weights[i]; j++) {
                int curVal = dp[i - 1][j] + weights[i];
                if (curVal > dp[i][j]) {
                    dp[i][j] = curVal;
                }
            }
        }
        int ret = -1;
        for (int i = w; i >= 0; i--) {
            ret = max(ret, dp[n - 1][i]);
        }
        return ret;
    }
};


int main() {
    // weight
    vector<vector<int>> weights = {{2, 2, 4, 6, 3}};
    // value
    vector<vector<int>> vals = {{3, 4, 8, 9, 6}};
    vector<int> ns = {5};
    vector<int> weis = {9};

    solution_knapsack sol;
    for (int i = 0; i < weights.size(); i++) {
        auto ret = sol.knapsack(weights[i], vals[i], ns[i], weis[i]);
        cout << "test " << i << " " << ret << endl;
    }
    return 0;
}