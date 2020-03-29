m = {
    '2': 'abc',
    '3': 'def',
    '4': 'ghi',
    '5': 'jkl',
    '6': 'mno',
    '7': 'pqrs',
    '8': 'tuv',
    '9': 'wxyz',
}

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        def f(size, str, pos):
            if pos >= size:
                res.append(str)
                return

            for item in l[pos]:
                f(size, str + item, pos + 1)
				
        l = []
        res = []    
            
        for c in digits:
            if c in m:
                l.append(m[c])
        
        if len(digits) > 0:
            f(len(digits), '', 0)
            
        return res
        