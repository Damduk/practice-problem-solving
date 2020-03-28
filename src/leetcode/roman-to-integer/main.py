dic = {
    'I': 1,
    'V': 5,
    'X': 10,
    'L': 50,
    'C': 100,
    'D': 500,
    'M': 1000,
}

class Solution:
    def romanToInt(self, s: str) -> int:
        res = 0
        last = None
        
        for c in s:
            num = dic[c]
            if last is None:
                last = num
                res += num
            else:
                if num > last:
                    res -= last
                    last = num - last
                else:
                    last = num
                    
                res += last

            
        return res