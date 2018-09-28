class Solution:
    def minCut(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        if not n:
            return 0
        dp = [[0 for _ in range(n)] for _ in range(n)]
        res = [0 for _ in range(n)]
        for l in range(0, n):
            for i in range(n - l):
                j = i + l
                if l == 0:
                    dp[i][j] = 1
                    continue
                if l == 1:
                    dp[i][j] = 1 if s[i] == s[j] else 0
                    continue
                if s[i] == s[j]:
                    dp[i][j] = dp[i+1][j-1]

        for j in range(n):
            res[j]=j
            for i in range(j+1):
                if dp[i][j]:
                    if i==0:
                        res[j]=0
                    else:
                        res[j]=min(res[i-1]+1, res[j])
        return res[n-1]

if __name__ == '__main__':
    print(Solution().minCut('aabab'))
