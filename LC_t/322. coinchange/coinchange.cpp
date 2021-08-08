#include "../public_utils/public_utils.h"


class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        int dp[amount + 1];
        for (int i = 1; i <= amount; i++) {
            dp[i] = INT_MAX;
        }
        dp[0] = 0;
        const int sz = coins.size();
        for (int i = 0; i < sz; i++) {
            if (coins[i] <= amount) dp[coins[i]] = 1;
        }

        for (int i = 1; i <= amount; i++) {
            if (dp[i] != INT_MAX) {
                for (int j = 0; j < sz; j++) {
                    if (coins[j] <= amount - i) {
                        dp[i + coins[j]] = min(dp[i + coins[j]], dp[i] + 1);
                    }
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }

    // dp: dp[i] = min(dp[i - coins[j]] + 1, ...)
};