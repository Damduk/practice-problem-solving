class Solution:
    def detectCapitalUse(self, word: str) -> bool:        
        def is_noncapital(c):
            return ord(c) - ord('a') >= 0
        
        if len(word) < 2:
            return True
        
        m = {
            True: { True: lambda c: is_noncapital(c) },
            False: {
                True: lambda c: is_noncapital(c),
                False: lambda c: not is_noncapital(c),
            },
        }
        
        f, s = is_noncapital(word[0]), is_noncapital(word[1])
        if f == True and s == False:
            return False
        
        isvalid = m[f][s]
        for c in word[2:]:
            if not isvalid(c):
                return False
            
        return True