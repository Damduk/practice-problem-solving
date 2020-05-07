# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        h = dict()
        def average(node, depth):
            val, cnt = h.get(depth, (0, 0))      
            h[depth] = (val + node.val, cnt + 1)
            
            if node.left:
                average(node.left, depth + 1)
            if node.right:
                average(node.right, depth + 1)
                
        average(root, 0)
        
        return [val / cnt for val, cnt in h.values()]