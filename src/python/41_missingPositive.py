# In O(n) time O(1) space search, use array itself as a hash tableI
class Solution:
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 1
        i, j = 0, len(nums)-1
        while j >= 0 and nums[j] <= 0:
            j -= 1
        while i < j:
            if nums[i] <= 0:
                nums[i], nums[j] = nums[j], nums[i]
                while nums[j] <= 0:
                    j -= 1
            i += 1
        i = 0
        while i <= j:
            if abs(nums[i]) > j + 1:
                i += 1
                continue
            nums[abs(nums[i])-1] = -nums[abs(nums[i])-1] if nums[abs(nums[i])-1]>0 else nums[abs(nums[i])-1]
            i+=1
        i = 0
        while i <= j:
            if nums[i]>0:
                return i+1
            i+=1
        return i+1

if __name__ == '__main__':
    print(Solution().firstMissingPositive([3,4,-1,1]))