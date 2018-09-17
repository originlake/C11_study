# Use dict in one loop
# dict[key] = value
class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        numdict = {}
        for i in range(len(nums)):
            diff = target - nums[i]
            if diff in numdict:
                return [numdict[diff], i]
            else:
                numdict[nums[i]] = i