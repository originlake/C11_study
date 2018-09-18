#     h o r s e   | if s1[i] == s2[j], no action need
#   0 1 2 3 4 5   |     dp[i][j] = dp[i-1][j-1]
# r 1 1 2 2 3 4   | else
# o 2 2 1 2 3 4   |     insert: dp[i][j] = dp[i-1][j]+1
# s 3 3 2 2 2 3   |     remove: dp[i][j] = dp[i][j-1]+1
# -----------------     replace: dp[i][j] = dp[i-1][j-1]+1
class Solution:
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        m, n = len(word2), len(word1)
        dp = [[0 for _ in range(n + 1)] for _ in range(m + 1)]
        for i in range(m + 1):
            dp[i][0] = i
        for j in range(n + 1):
            dp[0][j] = j

        for i in range(1,m+1):
            for j in range(1,n+1):
                if word2[i-1] == word1[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = min(dp[i - 1][j], dp[i][j-1], dp[i-1][j-1]) + 1
        return dp[-1][-1]