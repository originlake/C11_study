class Solution:
    def isInterleave(self, s1, s2, s3):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: bool
        """
        if len(s3) != len(s1+s2):
            return False
        dp = [[False for _ in range(len(s2)+1)] for _ in range(len(s1)+1)]
        s1, s2, s3 = '0'+s1, '0'+s2, '0'+s3
        for i in range(len(s1)):
            for j in range(len(s2)):
                if i+j == 0:
                    dp[i][j] = True
                elif i == 0:
                    dp[i][j] = s2[j] == s3[j] and dp[i][j-1]
                elif j == 0:
                    dp[i][j] = s1[i] == s3[i] and dp[i-1][j]
                else:
                    dp[i][j] = (s1[i] == s3[i+j] and dp[i-1][j]) or (s2[j]==s3[i+j] and dp[i][j-1])
        return dp[-1][-1]

if __name__ == '__main__':
    print(Solution().isInterleave('a','b','a'))