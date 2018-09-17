# Move two pointers from begin and end to center, always move pointer with smaller height first
class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        left, right = 0, len(height)-1
        maxA = 0
        while left != right:
            area = min(height[left], height[right])*(right - left)
            maxA = area if area > maxA else maxA
            if height[left] <= height[right]:
                left += 1
            else:
                right -=1
        return maxA
