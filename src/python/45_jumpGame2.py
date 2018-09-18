class Solution:
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) <= 1:
            return 0
        start, end, maxend = 0, 0, 0
        step = 0
        while end < len(nums)-1:
            step += 1
            for i in range(start, end + 1):
                if maxend >= len(nums)-1:
                    return step
                maxend = max(i + nums[i], maxend)
            start, end = end + 1, maxend
        return step

if __name__ == '__main__':
    print(Solution().jump([3,4,3,2,5,4,3]))
