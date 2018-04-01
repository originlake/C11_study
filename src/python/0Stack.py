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

a=stack()
print(a.isEmpty())