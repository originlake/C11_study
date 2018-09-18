class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        if not obstacleGrid or not obstacleGrid[0]:
            return 0
        if obstacleGrid[0][0] == 1:
            return 0
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        dp = [[0] * n for _ in range(m)]
        dp[0][0] = 1
        for i in range(m):
            for j in range(n):
                if obstacleGrid[i][j] == 1 or (i == 0 and j == 0):
                    continue
                dp[i][j] = (dp[i - 1][j] if i > 0 else 0) + (dp[i][j-1] if j > 0 else 0)
        return dp[m-1][n-1]


if __name__ == '__main__':
    print(Solution().uniquePathsWithObstacles([[0,0,0],[0,1,0],[0,0,0]]))