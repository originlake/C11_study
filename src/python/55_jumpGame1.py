class Solution:
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if not nums:
            return True
        i, j = 0, nums[0]
        while i <= j:
            j = max(j, i + nums[i])
            if j >= len(nums) - 1:
                return True
            i += 1
        return False