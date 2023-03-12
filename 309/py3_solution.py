class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        dp = [[float('-inf') for _ in range(3)] for _ in range(n + 1)]        
        dp[0][0] = 0

        for i in range(1, n + 1):
            p = prices[i - 1]
            
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1])
            dp[i][1] = dp[i - 1][2] + p
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][0] - p)
        
        return max(dp[n][0], dp[n][1], dp[n][2])