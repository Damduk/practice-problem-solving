# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

def makeNode(arr, l, r):
    sz = len(arr)
    if l > r or l >= sz:
        return None
    
    v = arr[l]
    pivot = r + 1
    for i in range(l + 1, min(r + 1, sz)):
        if v < arr[i]:
            pivot = i
            break
        
    res = TreeNode(v)
    res.left = makeNode(arr, l + 1, pivot - 1)
    res.right = makeNode(arr, pivot, r)
        
    return res
    
class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        return makeNode(preorder, 0, len(preorder) - 1)
        