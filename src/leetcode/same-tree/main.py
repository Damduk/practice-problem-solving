# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        def valid(p, q):
            if p is None or q is None:
                return False
            
            if p.val != q.val:
                return False
            
            ret = True
            if p.left:
                ret = ret and valid(p.left, q.left)
            elif q.left:
                return False
            
            if p.right:
                ret = ret and valid(p.right, q.right)
            elif q.right:
                return False
                
            return ret
        
        if p is None:
            return q is None
        
        return valid(p, q)