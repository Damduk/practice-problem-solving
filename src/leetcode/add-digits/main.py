class Solution:
    def addDigits(self, num: int) -> int:
        def divide(n):
            res = []
            while n:
                res.append(n % 10)
                n //= 10
            return res
        
        while num >= 10:
            num = sum(divide(num)) 
        
        return num