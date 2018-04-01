'''
Created on Mar 28, 2018

@author: 44386
'''
class stack:
    def __init__(self):
        self.s=[]
    def isEmpty(self):
        return False if self.s else True
    
    def push(self,x):
        self.s.append(x)
    
    def pop(self):
        return self.s.pop()

    def top(self):
        return self.s[-1]
class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
#         stack = []
#         dict = {"]":"[", "}":"{", ")":"("}
#         for char in s:
#             if char in dict.values():
#                 stack.append(char)
#             elif char in dict.keys():
#                 if stack == [] or dict[char] != stack.pop():
#                     return False
#             else:
#                 return False
#         return stack == []       
        a=stack()
        for b in s:
            if a.isEmpty():
                a.push(b)
                continue
            if a.top()=='[' and b==']':
                a.pop()
            elif a.top()=='(' and b==')':
                a.pop()
            elif a.top()=='{' and b=='}':
                a.pop()
            else: a.push(b)
        return True if a.isEmpty() else False
    
print(Solution().isValid(']]'))
        