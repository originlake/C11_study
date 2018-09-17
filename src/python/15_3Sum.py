class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        res = []
        i = 0
        while i < len(nums) - 2:
            # skip
            while 0 < i < len(nums) - 2 and nums[i] == nums[i - 1]:
                i += 1
            left, right = i + 1, len(nums) - 1
            while left < right:
                sum3 = nums[i] + nums[left] + nums[right]
                if sum3 == 0:
                    res.append([nums[i], nums[left], nums[right]])
                    left += 1
                    right -= 1
                    # skip duplicate values
                    while left < len(nums) and nums[left] == nums[left - 1]:
                        left += 1
                    while i < right < len(nums)  and nums[right] == nums[right + 1]:
                        right -= 1
                elif sum3 > 0:
                    right -= 1
                    # TLE why???
                    # while right < len(nums) and right > i and nums[right] == nums[right + 1]:
                    #     right -= 1
                else:
                    left += 1
                    # TLE why???
                    # while left < len(nums) and nums[left] == nums[left - 1]:
                    #     left += 1
            i += 1
        return res