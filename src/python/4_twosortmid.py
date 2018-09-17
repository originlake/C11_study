#       left_part          |        right_part
# A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1]
# B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]
# condition
# 1. conut(left_part) == count(right_part) or 1 larger
# 2. max(A[i-1], B[j-1]) < min(A[i], B[j])
# ps1: i,j can be 0 or m,n, remember to deal with this edge value
#
# ps2: why direct sort in python is faster than this O(log(min(m,n))) method?
# Because in Python build-in function should be faster than self implemented.
class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        # nums1 should be shorter than nums2
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        n, m = len(nums1), len(nums2)
        left, right = 0, n+1
        while left < right:
            mid = (left + right)//2
            mid2 = (n+m+1)//2 - mid
            maxl = nums2[mid2-1] if mid == 0 else nums1[mid-1] if mid2 == 0 else max(nums1[mid-1],nums2[mid2-1])
            minr = nums2[mid2] if mid == n else nums1[mid] if mid2 == m else min(nums1[mid], nums2[mid2])
            if maxl <= minr:
                return maxl if (n+m)%2 == 1 else (maxl+minr)/2
            # when mid = 0 or n, mid2 = 0 or m, it should always finish searching
            elif nums1[mid-1] > nums2[mid2]:
                right = mid
            elif nums2[mid2-1] > nums1[mid1]:
                left = mid+1



