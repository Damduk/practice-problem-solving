# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidSequence(self, root: TreeNode, arr: List[int]) -> bool:
        res = False
        def valid(node, idx):
            if idx < len(arr) and node.val != arr[idx]:
                return
            
            nonlocal res
            
            leaf = not node.left and not node.right
            if idx == len(arr) - 1 and leaf:
                res = True
                return
            
            if node.left:
                valid(node.left, idx + 1)
            if node.right:
                valid(node.right, idx + 1)
            
        valid(root, 0)
        return res