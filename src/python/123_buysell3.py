class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices:
            return 0
        hold0, hold1, sell0, sell1 = -prices[0], 0, 0, 0
        for x in prices:
            sell1 = max(sell1, hold1 + x)
            hold1 = max(hold1, sell0 - x)
            sell0 = max(sell0, hold0 + x)
            hold0 = max(hold0, -x)
        return sell1
if __name__=='__main__':
    print(Solution().maxProfit([3,3,5,0,0,3,1,4]))
