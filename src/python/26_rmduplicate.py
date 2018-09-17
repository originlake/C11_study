class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        num = None
        i= 0
        for j in range(len(nums)):
            if nums[j] != num:
                nums[i] = nums[j]
                i += 1
                num = nums[j]
        return nums

