#include "../public_utils/public_utils.h"

class Solution {
    int n;
    int helper(vector<vector<vector<int>>> &dp, int t, int x, int y, vector<vector<int>> &graph) {
        if (t == 2 * n)
            return 0;
        if (x == y)
            return dp[t][x][y] = 2;
        if (x == 0)
            return dp[t][x][y] = 1;
        if (dp[t][x][y] != -1)
            return dp[t][x][y];
        if (t % 2 == 0) {
            bool catWin = true;
            for (int i = 0; i < graph[x].size(); i++) {
                int nxt = graph[x][i];
                int ret = helper(dp, t + 1, nxt, y, graph);
                if (ret == 1)
                    return dp[t][x][y] = 1;
                else if (ret != 2)
                    catWin = false;
            }
            if (catWin)
                return dp[t][x][y] = 2;
            else
                return dp[t][x][y] = 0;
        } else {
            bool mouseWin = true;
            for (int i = 0; i < graph[y].size(); i++) {
                int nxt = graph[y][i];
                // cat cannot go 0
                if (nxt == 0)
                    continue;
                int ret = helper(dp, t + 1, x, nxt, graph);
                if (ret == 2)
                    return dp[t][x][y] = 2;
                else if (ret != 1)
                    mouseWin = false;
            }
            if (mouseWin)
                return dp[t][x][y] = 1;
            else
                return dp[t][x][y] = 0;
        }
        return 0;
    }

public:
    int catMouseGame(vector<vector<int>>& graph) {
        n = graph.size();
        vector<vector<vector<int>>> dp(2 * n, vector<vector<int>> (n, vector<int> (n, -1)));
        return helper(dp, 0, 1, 2, graph);
    }
};


int main() {
    vector<vector<vector<int>>> test = {
        {{2, 5}, {3}, {0, 4, 5}, {1, 4, 5}, {2, 3}, {0, 2, 3}}
    };
    Solution sol;
    for (int i = 0; i < test.size(); i++) {
        auto ret = sol.catMouseGame(test[i]);
        cout << i << " ret: " << ret << endl;
    }
    return 0;
}