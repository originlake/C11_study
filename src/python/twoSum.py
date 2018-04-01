'''
Created on Mar 22, 2018

@author: 44386
'''
# class Solution:
def twoSum(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: List[int]
    hashtable
    """
    nums_copy=list(nums)
    nums.sort()
    i=0
    j=len(nums)-1
    while(i!=j):
        sums=nums[i]+nums[j]
        if sums==target:
            if nums[i]==nums[j]:
                index1=nums_copy.index(nums[i])
                index2=nums_copy[index1+1:].index(nums[j])+index1+1
            else:
                index1=nums_copy.index(nums[i])
                index2=nums_copy.index(nums[j])
            ans=[index1,index2]
            ans.sort()
            return ans
        if sums>target:
            j=j-1
        if sums<target:
            i=i+1    
sum=5
nums=[3,3]
target=6
count=twoSum(nums,target)
print(count)
