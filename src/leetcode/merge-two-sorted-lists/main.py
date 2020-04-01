# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        root = ListNode(-1)
        head = root
        
        lp = l1
        rp = l2
        
        while lp is not None or rp is not None:
            if rp is None:
                head.next = ListNode(lp.val)
                head = head.next
                lp = lp.next
                continue
            elif lp is None:
                head.next = ListNode(rp.val)
                head = head.next
                rp = rp.next
                continue
            
            if lp.val < rp.val:
                head.next = ListNode(lp.val)
                head = head.next
                lp = lp.next
            else:
                head.next = ListNode(rp.val)
                head = head.next
                rp = rp.next
                
        return root.next
        
        