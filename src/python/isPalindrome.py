'''
Created on Mar 25, 2018

@author: 44386
'''
def isPalindrome(x):
#     return str(x)==str(x)[::-1]
    if x>=0 and x<10:
        return True
    if x<0:
        return False
    t=0
    s=x
    while(s>=10):
        t=t*10+s%10
        s=s//10
    return x//10==t and x%10==s
print(isPalindrome(-123210))    