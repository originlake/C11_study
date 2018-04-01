'''
Created on Mar 22, 2018

@author: 44386
'''
def lengthOfLongestSubstring(s):
    """
    :type s: str
    :rtype: int
    hashTable window
    """
    arr=list()
    n=len(s)
    max_len=0
    i=0
    while(i<n):
        if not s[i] in arr:
            arr.append(s[i])
            max_len=max(len(arr),max_len)
            i=i+1
        else:
            arr.pop(0)  
    return max_len

print(lengthOfLongestSubstring("aab"))