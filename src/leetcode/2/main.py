class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        num = numByListNode(l1) + numByListNode(l2)
        return listNodeByNum(num)
        
def numByListNode(li: ListNode):
    res = 0
    mux = 1
    cur = li
    
    while cur is not None:
        res = res + (cur.val * mux)
        cur = cur.next
        mux = mux * 10
    
    return res
    
def listNodeByNum(num):
    node = ListNode(0)
    root = node

    while True:
        node.val = int(num % 10)
        num = num // 10
        if num <= 0:
            break
        
        node.next = ListNode(0)
        node = node.next
    
    return root
