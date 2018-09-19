class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices:
            return 0
        minpri = prices[0]
        res = 0
        for x in prices:
            minpri = min(minpri, x)
            res = max(res, x - minpri)
        return res