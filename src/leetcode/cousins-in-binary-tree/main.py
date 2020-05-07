# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        def find(parent, node, t, depth):
            if node.val == t:
                return (parent.val if parent else None), depth
            
            ret = None
            if node.left:
                tmp = find(node, node.left, t, depth + 1)
                ret = tmp if tmp is not None else ret
            if node.right:
                tmp = find(node, node.right, t, depth + 1)
                ret = tmp if tmp is not None else ret
                
            return ret
        
        xval, xdep = find(None, root, x, 0)
        yval, ydep = find(None, root, y, 0)
        
        return xdep == ydep and xval != yval