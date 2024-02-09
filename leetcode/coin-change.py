class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [-1 for _ in range(amount+1)]
        dp[0] = 0
        coins.sort()
        coins = coins[::-1]
        for c in coins:
            for i in range(0, amount+1-c):
                if dp[i]==-1:
                    continue
                if dp[i+c]==-1:
                    dp[i+c] = dp[i]+1
                dp[i+c] = min(dp[i+c], dp[i]+1)
        return dp[amount]