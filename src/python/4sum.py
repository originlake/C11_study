'''
Created on Mar 27, 2018

@author: 44386
'''
class Solution:
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        ans=[]
        nums.sort()
        m=len(nums)
        i=0
        while(i<m-3):
            if nums[i]+nums[m-1]*3<target:  # nums[i] is too small
                i+=1
                continue
            if 4*nums[i]>target:            # nums[i] is too large
                break
            if i>0 and nums[i]==nums[i-1]:
                i+=1
                continue
            j=i+1
            while(j<len(nums)-2):
                if nums[j]+nums[m-1]*2<target-nums[i]:
                    j+=1
                    continue
                if nums[j]*3>target-nums[i]:
                    break
                if j>i+1 and nums[j]==nums[j-1]:
                    j+=1
                    continue
                l,r=j+1,len(nums)-1
                while(l<r):
                    s=nums[i]+nums[j]+nums[l]+nums[r]
                    if s<target:
                        l+=1
                    elif s>target:
                        r-=1
                    else:
                        ans.append([nums[i],nums[j],nums[l],nums[r]])
                        while(l<r and nums[l]==nums[l+1]):
                            l+=1
                        l+=1
                        while(l<r and nums[r]==nums[r-1]):
                            r-=1
                        r-=1
                j+=1
            i+=1
        return ans
a=[1, 0, -1, 0, -2, 2]
print(Solution().fourSum(a,0))