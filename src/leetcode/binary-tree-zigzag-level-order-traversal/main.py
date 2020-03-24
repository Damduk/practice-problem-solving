import queue

def bfs(root: TreeNode):
    res = dict({})
    
    q = queue.Queue()
    q.put((root, 0))
    
    while (q.qsize()): 
        node, lv = q.get()
        if not lv in res:
            res[lv] = []
            
        res[lv].append(node.val)
        if node.left is not None:
            q.put((node.left, lv + 1))
        if node.right is not None:
            q.put((node.right, lv + 1))
    
    return res

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        res = []
        if root is None:
            return res
        
        siblings = bfs(root)
        for k, v in siblings.items():
            if k & 1:
                siblings[k].reverse()
        
        for k, v in siblings.items():
            res.append(v)
        
        return res
        