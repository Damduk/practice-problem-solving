def solve(s, l, r):
    size = len(s)
    
    sub = ''
    while l >= 0 and r < size and s[l] == s[r]:
        sub = s[l] if l == r else s[l] + sub + s[r] 
        l = l - 1
        r = r + 1
        
    return sub

def max_res(a, b):
    return a if len(a) > len(b) else b

class Solution:
    def longestPalindrome(self, s: str) -> str:
        size = len(s)
        if size <= 1:
            return s
      
        res = ""
        for i in range(size):
            res = max_res(res, solve(s, i, i))
            res = max_res(res, solve(s, i, i + 1))

        return res
        