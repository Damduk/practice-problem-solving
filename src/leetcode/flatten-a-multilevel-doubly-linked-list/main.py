"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""

class Solution:
    def flatten(self, head: 'Node') -> 'Node':      
        def normalize(node):
            cur = node
            while True:
                if cur.child:
                    tail = normalize(cur.child)
                    cur.child.prev = cur
                    tail.next = cur.next
                    if cur.next:
                        cur.next.prev = tail
                    cur.next = cur.child
                    cur.child = None
                    
                if cur.next is None:
                    break
                    
                cur = cur.next
                
            return cur
        
        if head:
            normalize(head)
    
        return head