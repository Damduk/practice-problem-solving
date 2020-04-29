# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        ans = -2000000000000000
        
        def dfs(node):
            nonlocal ans
            
            res = node.val
            l = dfs(node.left) if node.left else 0
            r = dfs(node.right) if node.right else 0
            
            ret = max(res + l, res + r, res)
            ans = max(ans, res + l + r, ret)
            
            return ret
        
        dfs(root)
        
        return ans