'''
Created on Mar 24, 2018

@author: 44386
'''
def reverse(x):
    """
    :type x: int
    :rtype: int
    """
    ans=0
    mult=1
    if x<0:
        x=-x 
        mult=-1
    
    while(x!=0):
        tail=x%10
        ans=ans*10+tail
        x=x//10
        if ans>=2**31:
            return 0
    return mult*ans

print(reverse(1534236469))