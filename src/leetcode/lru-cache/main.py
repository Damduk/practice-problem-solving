class Node:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.next = None
        self.prev = None

SENTINEL_NODE = -1
    
    
class LRUCache:

    def __init__(self, capacity: int):
        self.hash = dict()
        self.head = Node(SENTINEL_NODE, SENTINEL_NODE)
        self.tail = Node(SENTINEL_NODE, SENTINEL_NODE)
        self.cap = capacity
        
        self.head.next = self.tail
        self.tail.prev = self.head
        
    def remove(self, node):
        node.prev.next = node.next
        node.next.prev = node.prev
        del self.hash[node.key]
    
    def insert(self, node):
        self.head.next.prev = node
        node.next = self.head.next
        node.prev = self.head
        self.head.next = node
        
        self.hash[node.key] = node
        
    def get(self, key: int) -> int:
        node = self.hash.get(key)
        if not node:
            return -1
        
        self.remove(node)
        self.insert(node)
        
        return abs(node.val)
        

    def put(self, key: int, value: int) -> None:
        node = self.hash.get(key)
        if node:
            self.remove(node)
        else:     
            if len(self.hash) >= self.cap:
                self.remove(self.tail.prev)
            
        new_node = Node(key, value)
        self.insert(new_node)


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)