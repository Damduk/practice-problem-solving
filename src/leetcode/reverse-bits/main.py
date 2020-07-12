class Solution:
    def reverseBits(self, n: int) -> int:
        res = 0 
        for i in range(32):
            b = 1 & (n >> (31 - i))
            res |= (b << i)
        
        return res