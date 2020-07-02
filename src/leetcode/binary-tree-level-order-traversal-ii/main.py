# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        res = []
        
        def dfs(node, lv):
            nonlocal res
            
            if len(res) - 1 < lv:
                res.append(list())
            
            res[lv].append(node.val)
            
            if node.left:
                dfs(node.left, lv + 1)
            if node.right:
                dfs(node.right, lv + 1)
                
        if root:
            dfs(root, 0)
        
        return reversed(res)