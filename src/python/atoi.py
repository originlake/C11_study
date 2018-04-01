'''
Created on Mar 24, 2018

@author: 44386
'''
def myAtoi(str):
    """
    :type str: str
    :rtype: int
    """
    if len(str)==0:
        return 0
    s=list(str.strip())
    ans=0
    if s[0]=='-':
        mult=-1
    else: mult=1
    if s[0] in ['+','-']:
        s.pop(0)
    i=0
    while(s[i].isdigit() and i<len(s)):
        ans=10*ans+int(s[i])
        i+=1
    ans=ans*mult
    ans=max(-2**31,ans)
    ans=min(2**31-1,ans)
    return ans
    
    
print(myAtoi('              2147483649avv'))
    
        