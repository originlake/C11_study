# carry, remainder
#
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head = ListNode(0)
        ptr = head
        res = 0
        while l1 or l2 or res:
            add = (l1.val if l1 else 0) + (l2.val if l2 else 0) + res
            res = 1 if add >= 10 else 0
            add = add - 10 if add >= 10 else add
            ptr.next = ListNode(add)
            ptr = ptr.next
            l1 = l1.next if l1 else l1
            l2 = l2.next if l2 else l2

        return head.next



