class Solution:
    def findComplement(self, num: int) -> int:
        def tobitset(num):
            bits = list()
            while num:
                n = num % 2
                num //= 2
                
                bits.append(int(not n))
            
            return bits
        
        def todecimal(bits):
            res = 0
            c = 0
            
            for b in bits:
                res += b * pow(2, c) 
                c += 1
            
            return res
        
        bits = tobitset(num)
        res = todecimal(bits)
        
        return res