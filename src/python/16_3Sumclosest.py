class Solution:
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        res = sum(nums[0:3])
        i = 0
        while i < len(nums)-2:
            while i > 0 and i < len(nums)-2 and nums[i] == nums[i-1]:
                i += 1
            left, right = i+1, len(nums)-1
            while left < right:
                sum3 = nums[i] + nums[left] + nums[right]
                res = sum3 if abs(sum3 - target) < abs(res - target) else res
                if sum3 == target:
                    return target
                elif sum3 > target:
                    right -= 1
                    while right > i and nums[right] == nums[right+1]:
                        right -= 1
                else:
                    left += 1
                    while left < len(nums) and nums[left] == nums[left-1]:
                        left += 1
            i += 1
        return res

if __name__ == '__main__':
    print(Solution().threeSumClosest([1,1,-1,-1,3], -1))