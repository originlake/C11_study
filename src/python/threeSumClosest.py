'''
Created on Mar 26, 2018

@author: 44386
'''
def threeSumClosest(nums,target):
    nums.sort()
    i=0
    ans=nums[0]+nums[1]+nums[2]
    mi=abs(ans-target)
    while(i<len(nums)-2):
        if i>0 and nums[i]==nums[i-1]:
            i+=1
            continue
        l,r=i+1,len(nums)-1
        while(l<r):
            s=nums[i]+nums[l]+nums[r]
            if abs(s-target)==0:
                return s
            if abs(s-target)<mi:
                mi=abs(s-target)
                ans=s
            if s<target:
                l+=1
            else:
                r-=1
#             while(l<r and nums[l]==nums[l+1]):
#                 l+=1
#             while(l<r and nums[r]==nums[r-1]):
#                 r-=1
        i+=1
    return ans
print(threeSumClosest([1,1,1,0],-100))      