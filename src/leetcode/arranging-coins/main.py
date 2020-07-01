class Solution:
    def arrangeCoins(self, n: int) -> int:
        l = 0
        r = n
        
        while l <= r:
            k = (l + r) // 2
            cur = k * (k + 1) // 2
            
            if cur == n:
                return k
            elif cur < n:
                l = k + 1
            else:
                r = k - 1
        
        return r