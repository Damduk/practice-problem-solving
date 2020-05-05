class Node:
    def __init__(self, idx):
        self.next = None
        self.prev = None
        self.idx = idx
    def __str__(self):
        return f'{self.idx}'


class Solution:
    def firstUniqChar(self, s: str) -> int:
        def remove(node):
            node.next.prev = node.prev
            node.prev.next = node.next
        
        def append(tail, node):
            tail.prev.next = node
            node.prev = tail.prev
            tail.prev = node
            node.next = tail
        
        head = Node(-1)
        tail = Node(-1)
        
        head.next = tail
        tail.prev = head
        
        cs = set()
        nodes = dict()
        for idx, c in enumerate(s):
            if c in cs:
                n = nodes.get(c)
                if n:
                    remove(n)
                    del nodes[c]
            else:
                cs.add(c)
                n = Node(idx)
                append(tail, n)
                nodes[c] = n
                
        return head.next.idx