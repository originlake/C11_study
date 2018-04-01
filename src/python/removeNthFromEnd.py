'''
Created on Mar 28, 2018

@author: 44386
'''
# Definition for singly-linked list.
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
class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        if n==0:
            return head
        nth=head
        x=head
        while(n>0):
            x=x.next
            n-=1
        if x==None:
            return head.next
        while(x.next is not None):
            x=x.next
            nth=nth.next
        if nth.next.next is not None:
            nth.next=nth.next.next
        else:
            nth.next=None
        return head
              
head=ListNode(0)
head.genTest(5)
Solution().removeNthFromEnd(head, 3)
head.disp()

