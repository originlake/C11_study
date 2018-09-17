# careful design to skip useless computation
class Solution:
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        nums.sort()
        res = []
        i = 0
        while i < len(nums) -3:
            # too small
            if nums[i] + nums[-1]*3 <target:
                i+=1
                continue
            # too large
            if 4*nums[i] > target:
                break
            while 0 < i < len(nums)-3 and nums[i]==nums[i-1]:
                i+=1
            j = i+1
            while j < len(nums)-2:
                if nums[i]+nums[j]+nums[-1]*2 < target:
                    j += 1
                    continue
                if nums[i]+nums[j]*3 > target:
                    break
                while i+1 < j < len(nums) - 2 and nums[j] == nums[j - 1]:
                    j += 1
                sum2 = target - nums[i] - nums[j]
                left, right= j+1, len(nums)-1
                while left < right:
                    sum1 = nums[left] + nums[right] - sum2
                    if sum1 == 0:
                        res.append([nums[i], nums[j], nums[left], nums[right]])
                        left += 1
                        right -= 1
                        while right > j and nums[right] == nums[right+1]:
                            right -= 1
                        while left < len(nums) and nums[left] == nums[left - 1]:
                            left += 1
                    elif sum1 > 0:
                        right -= 1
                        while right > j and nums[right] == nums[right+1]:
                            right -= 1
                    else:
                        left += 1
                        while left < len(nums) and nums[left] == nums[left - 1]:
                            left += 1
                j += 1
            i += 1
        return res

if __name__ == '__main__':
    print(Solution().fourSum([1,0,-1,0,-2,2],0))