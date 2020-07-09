# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        if not root:
            return 0
        
        l = list()
        def dfs(node, lv = 0, idx = 1):
            l.append((lv, idx))
            
            if node.left:
                dfs(node.left, lv + 1, idx * 2)
            if node.right:
                dfs(node.right, lv + 1, idx * 2 + 1)
        
        dfs(root)
        
        asc = sorted(l, key=lambda t: (t[0], t[1]))
        desc = sorted(l, key=lambda t: (t[0], -t[1]))
        
        res = 1
        while len(asc):
            l = asc.pop()
            p = desc.pop()
            
            diff = abs(l[1] - p[1])
            if diff != 0:
                res = max(res, diff + 1)
        
        return res