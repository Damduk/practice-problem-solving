# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        def fill(l, r, node):
            v = postorder.pop()
            idx = inorder.index(v)
            node.val = v
        
            if idx + 1 <= r:
                node.right = TreeNode()
                fill(idx + 1, r, node.right)
            
            if l <= idx - 1:
                node.left = TreeNode()
                fill(l, idx - 1, node.left)
        
        if not inorder:
            return None
        
        root = TreeNode()
        fill(0, len(inorder) - 1, root)    
        
        return root
    