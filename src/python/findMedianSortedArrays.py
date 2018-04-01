'''
Created on Mar 23, 2018

@author: 44386
'''
# def findIndex(nums,x):
#     i=len(nums)//2
#     if nums[i]>x:
#         if len(nums)<2:
#             return 0
#         else:
#             return findIndex(nums[:i],x)
#     else:
#         if len(nums)<2:
#             return 1
#         else:
#             return i+findIndex(nums[i:],x)
# 
# def findT(nums1,nums2,ex):
#     tlen=len(nums1)+len(nums2)
#     low=0
#     high=len(nums1)-1
#     while(low<high):
#         mid=(low+high)//2
#         ind=findIndex(nums2, nums1[mid])
#         left=mid+ind+1
#         right=tlen-left
#         if left>=right:
#             if left-right<2:
#                 break
#             else: 
#                 high=mid
#         else:
#             if right-left<2:
#                 break
#             else:
#                 low=mid+1
#     mid=(low+high)//2
#     ind=findIndex(nums2, nums1[mid])
#     left=mid+ind+1
#     right=tlen-left
#     if left==right:
#         return [max(nums1[mid],nums2[ind-1] if ind>0 else 0),min(nums1[mid+1],nums2[ind]) if mid<len(nums1)-1 else nums2[ind]]
#     elif left-right==1:
#         return [max(nums1[mid],nums2[ind-1] if ind>0 else 0)]
#     elif right-left==1:
#         return [min(nums1[mid+1],nums2[ind]) if mid<len(nums1)-1 else nums2[ind]]
#     elif left>right:
#         return [min(nums2[ex-mid],nums1[mid]),min(nums1[mid],nums2[ex+1-mid])]
#     
# def findMedianSortedArrays(nums1, nums2):
#     """
#     :type nums1: List[int]
#     :type nums2: List[int]
#     :rtype: float
#     """
#     l=len(nums1)+len(nums2)
#     if l%2==1:
#         ex=l//2
#     else:
#         ex=l//2-1
#     if len(nums1)>0 and len(nums2)>0:
#         a=findT(nums1,nums2,ex)
#         ans=sum(a)/len(a)
#     else:
#         if len(nums2)==0:
#             nums=nums1
#         if len(nums1)==0:
#             nums=nums2
#         if len(nums)%2==0:
#             ans=(nums[ex]+nums[ex+1])/2
#         else:
#             ans=nums[ex]
#     return ans
#     
#     
#     
#     
# 
# nums=[1,2,3,4,5,7,9]
# print(findMedianSortedArrays([1,2,9,10], [4,10]))
'''
Just because sort in python 
'''
def findMedianSortedArrays(nums1, nums2):
    nums=nums1+nums2
    nums.sort()
    l=len(nums)
    if l%2==1:
        return nums[l//2]
    else:
        return (nums[l//2-1]+nums[l//2])/2

print(findMedianSortedArrays([1,2,3,4], [2,4]))