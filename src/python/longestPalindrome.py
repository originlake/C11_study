'''
Created on Mar 24, 2018

@author: 44386
'''
def longestPalindrome(s):
    ans=''
    maxlen=0
    for i in range(len(s)):
        a=s[i]
        j=i-1
        k=i+1
#         Strating as 'a'
        while(j>=0 and k<len(s)):
            if s[j]==s[k]:
                a=s[j]+a+s[j]
                j-=1
                k+=1
            else:
                break
        if maxlen<len(a):
            maxlen=len(a)
            ans=a
#         Strating as 'aa'
        if k<len(s) and s[i]==s[i+1]:
            a=s[i]+s[i]
            j=i-1
            k=i+2
            while(j>=0 and k<len(s)):
                if s[j]==s[k]:
                    a=s[j]+a+s[j]
                    j-=1
                    k+=1
                else:
                    break
            if maxlen<len(a):
                maxlen=len(a)
                ans=a
    return ans  

print(longestPalindrome('aaaa'))
        
        