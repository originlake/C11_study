#     b a g |   dp[i][j] = 0 if i<j
#   1 0 0 0 |   dp[i][j] = dp[i-1][j] if s[i]!=s[j]
# b 1 1 0 0 |   dp[i][j] = dp[i-1][j]+dp[i-1][j-1] if s[i]==s[j]
# a 1 1 1 0 |
# b 1 2 1 0 |
# g 1 2 1 1 |
# b 1 3 1 1 |
# a 1 3 4 1 |
# g 1 3 4 5 |
class Solution:
    def numDistinct(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        m, n = len(s), len(t)
        dp = [[0 for _ in range(n+1)] for _ in range(m+1)]
        for i in range(m+1):
            dp[i][0] = 1
        for i in range(1, m+1):
            for j in range(1, i+1):
                if s[i] != t[j]:
                    dp[i][j] = dp[i-1][j]
                else:
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
        return dp[-1][-1]
