# k-transactions
# T[i][j] = max --- T[i][j-1]
#                |- Price[j] - Price[m] + T[i-1][m] (m = 0:j)
# improved
# T[i][j] = max --- T[i][j-1]
#                |- Price[j] + diff
# diff = max(diff, T[i-1][j] - Price[j])
class Solution:
    def maxProfit(self, k, prices):
        """
        :type k: int
        :type prices: List[int]
        :rtype: int
        """
        if not prices:
            return 0
        if k >= len(prices) // 2:
            return sum(
                x - y
                for x, y in zip(prices[1:], prices[:-1])
                if x > y)

        res = [0 for _ in range(len(prices))]
        for i in range(k):
            diff = -prices[0]
            for j in range(1, len(prices)):
                tmpdiff = res[j] - prices[j]
                res[j] = max(res[j - 1], prices[j] + diff)
                diff = max(diff, tmpdiff)
        return res[-1]