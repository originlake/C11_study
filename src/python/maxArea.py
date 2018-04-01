'''
Created on Mar 25, 2018

@author: 44386
'''

def maxArea(height):
    """
    :type height: List[int]
    :rtype: int
    """
    i=0
    j=len(height)-1
    ma=min(height[i],height[j])*(j-i)
    while(i<j):
        if height[i]<=height[j]:
            t=i+1
            while(height[i]>height[t] and t<j):
                i+=1
            i=t
            if ma<min(height[t],height[j])*(j-t):
                ma=min(height[t],height[j])*(j-t)
            if t==j:
                break
        else:
            t=j-1
            while(height[j]>height[t] and t>i):
                t-=1
            j=t
            if ma<min(height[i],height[t])*(t-i):
                ma=min(height[i],height[t])*(t-i)
            if t==i:
                break
    return ma
print(maxArea([1,3,2,3,9,1,9,5,1]))