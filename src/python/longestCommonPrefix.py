'''
Created on Mar 26, 2018

@author: 44386
'''
def longestCommonPrefix(strs):
    ans=''
    isEnd=False
    if not strs:
        return ans
    if not strs[0]:
        return ans
    x=strs[0]
    i=0
    while(not isEnd):
        if len(x)==i:
            break
        letter=x[i]
        for s in strs:
            if not s:
                isEnd=True
                break
            elif len(s)==i:
                isEnd=True
                break
            elif s[i]!=letter:
                isEnd=True
                break
        if not isEnd:
            ans=ans+letter
            i=i+1
    return ans
'''
@syrupmachine
nicely using zip
# zip('ABCD', 'xy') --> Ax By
'''
# def longestCommonPrefix(self, strs):
#     if not strs:
#         return ""
#         
#     for i, letter_group in enumerate(zip(*strs)):
#         if len(set(letter_group)) > 1:
#             return strs[0][:i]
#     else:
#         return min(strs)
strs=[]
print(longestCommonPrefix(strs))    