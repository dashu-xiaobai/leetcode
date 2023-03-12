const int INF = 1e9;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(3));

        dp[0][0] = 0; dp[0][1] = -INF; dp[0][2] = -INF;
        for (int i = 1; i <= n; i++) {
            int p = prices[i - 1];

            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][2] + p;
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][0] - p);
        }

        return max({dp[n][0], dp[n][1], dp[n][2]});
    }
};