'''
Created on Mar 22, 2018

@author: 44386
'''
'''
ListNode
'''
class ListNode:
    def __init__(self,val):
        self.val=val
        self.next=None
    
def addTwoNumbers(l1, l2):
    idx=ListNode(None)
    n=idx
    res=0
    while(l1.next!=None or l2.next!=None or res==1):
        a=l1.val if l1!=None else 0
        b=l2.val if l2!=None else 0
        sums=a+b+res
        res=0
        if sums>9:
            sums=sums-10
            res=1
        n.next=ListNode(sums)
        n=n.next
        if l1!=None:
            l1=l1.next
        if l2!=None:
            l2=l2.next
    return idx.next


