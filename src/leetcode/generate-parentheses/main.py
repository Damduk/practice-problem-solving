def solve(l, s, a, b):
    if a == 0 and b == 0:
        l.append(s)
        return
    
    if a > 0:
        solve(l, s + '(', a - 1, b + 1)
    if b > 0:
        solve(l, s + ')', a, b - 1)

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        
        solve(res, '', n, 0)
        
        return res