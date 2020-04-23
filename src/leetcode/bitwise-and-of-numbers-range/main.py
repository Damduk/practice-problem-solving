class Solution:
    def rangeBitwiseAnd(self, m: int, n: int) -> int:
        if m == 0:
            return 0
        
        cnt = 1
        while m != n:
            m >>= 1
            n >>= 1
            cnt <<= 1
        
        return m * cnt