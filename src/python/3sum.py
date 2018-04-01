'''
Created on Mar 26, 2018

@author: 44386
'''
def threeSum(nums):
#     TLE
#     ans=[]
#     count=dict()
#     for x in nums:
#         count[str(x)]=count.get(str(x),0)+1
#     if count.get('0',0)>2:
#         ans.append([0,0,0])      
#     for k in list(count):
#         s=int(k)
#         if count[k]<2: del count[k]
#         for x in count:
#             tar=-int(x)-s
#             if x==k or str(tar)==k:
#                 continue
#             if tar==int(x) and count.get(str(tar),0)>1:
#                 a=sorted([s,int(x),tar])
#                 if a not in ans:
#                     ans.append(sorted([s,int(x),tar]))
#             elif tar!=int(x) and count.get(str(tar),0)>0:
#                 a=sorted([s,int(x),tar])
#                 if a not in ans:
#                     ans.append(sorted([s,int(x),tar]))
#       
#     return ans

    nums.sort()
    ans=[]
    i=0
    while(i<len(nums)-2):
        while(i>0 and i<len(nums)-2 and nums[i]==nums[i-1]):
            i+=1
        l,r=i+1,len(nums)-1
        while(l<r):
            s=nums[i]+nums[l]+nums[r]
            if s<0:
                l+=1
            elif s>0:
                r-=1
            else:
                ans.append([nums[i],nums[l],nums[r]])
                while(l<r and nums[l]==nums[l+1]):
                    l+=1
                while(l>r and nums[r]==nums[l-1]):
                    r-=1
                l+=1
                r-=1
        i+=1
    return ans
print(threeSum([-1,0,1,2,-1,-4]))   