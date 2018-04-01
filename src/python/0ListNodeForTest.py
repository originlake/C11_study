'''
Created on Mar 28, 2018

@author: 44386
'''
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
    
    def disp(self):
        print(self.val,end='')
        x=self.next
        while(x is not None):
            print('->'+str(x.val),end='')
            x=x.next
    def genTest(self,n):
        x=self
        for i in range(5):
            x.next=ListNode(i+1)
            x=x.next